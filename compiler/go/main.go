package main

import (
	"fmt"
	"os"
)

// Reader Class
type Reader struct {
	Data  string
	Index int
}

func NewReader(data string) *Reader {
	return &Reader{
		Data:  data,
		Index: 0,
	}
}

func (r *Reader) NextChar() byte {
	if r.Index >= len(r.Data) {
		return 0xFF
	}
	ret := r.Data[r.Index]
	r.Index += 1
	return ret
}

func (r *Reader) Retract() {
	if r.Index > 0 {
		r.Index -= 1
	}
}

// Token Class
type Token struct {
	Type  string
	Value string
}

// Scanner Class
type Scanner struct {
	Reader       *Reader
	currentToken *Token
	currLine     int
	state        int
}

func NewScanner(reader *Reader) *Scanner {
	return &Scanner{
		Reader:       reader,
		currentToken: new(Token),
		currLine:     1,
		state:        0,
	}
}

func (s *Scanner) makeToken(type_ string, value string) Token {
	s.currentToken.Type = type_
	s.currentToken.Value = value
	return *s.currentToken
}

var dataString = `int a = 1; // aaa
int b = 2;

/* print a or b according to c */

bool c = true;
if (c){
    print a;
} else {
    print b;
}
int i = 0;
while (i < 10){
    print i;
    i++;
}`

var START_STATE = 0
var IDENTIFIER_STATE = START_STATE + 1
var NUMBER_STATE = IDENTIFIER_STATE + 1
var SLASH_STATE = NUMBER_STATE + 1

func (s *Scanner) nextToken() Token {
	var bufferStr string
	for {
		switch s.state {
		case START_STATE:
			c := s.Reader.NextChar()
			if (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') {
				s.state = IDENTIFIER_STATE
				bufferStr += string(c)
			} else if c >= '0' && c <= '9' {
				s.state = NUMBER_STATE
				bufferStr += string(c)
			} else if c == '/' {
				s.state = SLASH_STATE
				bufferStr += string(c)
			} else if c == ';' {
				return s.makeToken("semicolon", ";")
			} else if c == '{' {
				return s.makeToken("left_brace", "{")
			} else if c == '}' {
				return s.makeToken("right_brace", "}")
			} else if c == '(' {
				return s.makeToken("left_paren", "(")
			} else if c == ')' {
				return s.makeToken("right_paren", ")")
			} else if c == '+' {
				d := s.Reader.NextChar()
				if d == '=' {
					return s.makeToken("plusassign", "+=")
				} else if d == '+' {
					return s.makeToken("increment", "++")
				} else {
					s.Reader.Retract()
					return s.makeToken("plus", "+")
				}
			} else if c == '-' {
				d := s.Reader.NextChar()
				if d == '=' {
					return s.makeToken("minusassign", "-=")
				} else if d == '-' {
					return s.makeToken("decrement", "--")
				} else {
					s.Reader.Retract()
					return s.makeToken("minus", "-")
				}
			} else if c == '*' {
				d := s.Reader.NextChar()
				if d == '=' {
					return s.makeToken("multiplyassign", "*=")
				} else {
					s.Reader.Retract()
					return s.makeToken("multiply", "*")
				}
			} else if c == '=' {
				d := s.Reader.NextChar()
				if d == '=' {
					return s.makeToken("equal", "==")
				} else {
					s.Reader.Retract()
					return s.makeToken("assign", "=")
				}
			} else if c == '<' {
				d := s.Reader.NextChar()
				if d == '=' {
					return s.makeToken("less_equal", "<=")
				} else {
					s.Reader.Retract()
					return s.makeToken("less", "<")
				}
			} else if c == '>' {
				d := s.Reader.NextChar()
				if d == '=' {
					return s.makeToken("greater_equal", ">=")
				} else {
					s.Reader.Retract()
					return s.makeToken("greater", ">")
				}
			} else if c == '!' {
				d := s.Reader.NextChar()
				if d == '=' {
					return s.makeToken("not_equal", "!=")
				} else {
					s.Reader.Retract()
					return s.makeToken("not", "!")
				}
			} else if c == ' ' || c == '\t' || c == '\n' || c == '\r' {
				if c == '\n' {
					s.currLine += 1
				}
				continue
			} else if c == 0xFF {
				s.currentToken.Type = "eof"
				return s.makeToken("eof", "eof")
			} else {
				s.currentToken.Type = "error"
				return s.makeToken("error", string(c))
			}
		case IDENTIFIER_STATE:
			c := s.Reader.NextChar()
			if (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') {
				bufferStr += string(c)
			} else {
				s.state = START_STATE
				s.Reader.Retract()
				if bufferStr == "int" {
					return s.makeToken("int", bufferStr)
				} else if bufferStr == "bool" {
					return s.makeToken("bool", bufferStr)
				} else if bufferStr == "true" {
					return s.makeToken("true", bufferStr)
				} else if bufferStr == "false" {
					return s.makeToken("false", bufferStr)
				} else if bufferStr == "if" {
					return s.makeToken("if", bufferStr)
				} else if bufferStr == "else" {
					return s.makeToken("else", bufferStr)
				} else if bufferStr == "while" {
					return s.makeToken("while", bufferStr)
				} else if bufferStr == "print" {
					return s.makeToken("print", bufferStr)
				}
				return s.makeToken("identifier", bufferStr)
			}
		case NUMBER_STATE:
			c := s.Reader.NextChar()
			if c >= '0' && c <= '9' {
				bufferStr += string(c)
			} else {
				s.state = START_STATE
				s.Reader.Retract()
				return s.makeToken("integer", bufferStr)
			}
		case SLASH_STATE:
			c := s.Reader.NextChar()
			if c == '/' {
				bufferStr = ""
				d := s.Reader.NextChar()
				if d != '\r' && d != '\n' {
					for d != '\r' && d != '\n' {
						bufferStr += string(d)
						d = s.Reader.NextChar()
					}
				}
				s.state = START_STATE
				return s.makeToken("linecomment", "//"+bufferStr)
			} else if c == '*' {
				bufferStr = ""
				d := s.Reader.NextChar()
				for d != '*' {
					if d == 0xFF {
						return s.makeToken("error", "block comment not terminated")
					}
					bufferStr += string(d)
					d = s.Reader.NextChar()
				}
				d = s.Reader.NextChar()
				if d == '/' {
					s.state = START_STATE
					return s.makeToken("blockcomment", "/*"+bufferStr+"*/")
				}
				return s.makeToken("error", "block comment not terminated")
			} else if c == '=' {
				s.state = START_STATE
				return s.makeToken("divideassign", "/=")
			} else {
				s.Reader.Retract()
				s.state = START_STATE
				return s.makeToken("divide", "/")
			}
		default:
			return s.makeToken("error", "unknown state")
		}
	}
}

// <program>       ::= <statements>
// <statements>    ::= <statement> <statements>
//                  | ε
// <statement>     ::= <declaration>
//                  | <comment>
//                  | <if_statement>
//                  | <while_loop>
//                  | <print_statement>
//                  | <increment>
// <declaration>   ::= "int" <identifier> "=" <expression> ";"
//                  | "bool" <identifier> "=" <boolean> ";"
// <comment>       ::= "//" <comment_text>
//                  | "/*" <comment_text> "*/"
// <if_statement>  ::= "if" "(" <expression> ")" "{" <statements> "}"
//                      "else" "{" <statements> "}"
// <while_loop>    ::= "while" "(" <expression> ")" "{" <statements> "}"
// <print_statement> ::= "print" <expression> ";"
// <increment>     ::= <identifier> "++" ";"
// <expression>    ::= <integer>
//                  | <boolean>
//                  | <identifier>
//                  | <comparison>
// <boolean>       ::= "true"
//                  | "false"
// <comparison>    ::= <expression> "<" <expression>
//                  | <expression> ">" <expression>
//                  | <expression> "<=" <expression>
//                  | <expression> ">=" <expression>
//                  | <expression> "==" <expression>
//                  | <expression> "!=" <expression>
// <identifier>    ::= [a-zA-Z_][a-zA-Z0-9_]*
// <integer>       ::= [0-9]+

// Parser Class
type Parser struct {
	tokens       []Token
	currentIndex int
}

func NewParser(tokens []Token) *Parser {
	return &Parser{
		tokens:       tokens,
		currentIndex: 0,
	}
}

func (p *Parser) PeekToken() Token {
	return p.tokens[p.currentIndex]
}

func (p *Parser) ConsumeToken(expectedToken Token) Token {
	token := p.PeekToken()
	if token.Type == expectedToken.Type && token.Value == expectedToken.Value {
		p.currentIndex += 1
		return token
	} else {
		os.Exit(-1)
		return Token{}
	}
}

func main() {
	fmt.Println(dataString)

	reader := NewReader(dataString)
	scanner := NewScanner(reader)
	for {
		token := scanner.nextToken()
		fmt.Println(token)
		if token.Type == "eof" {
			break
		}
	}
}
