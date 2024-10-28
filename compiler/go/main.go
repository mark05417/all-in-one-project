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
	if token.Type == expectedToken.Type { // && token.Value == expectedToken.Value {
		p.currentIndex += 1
		return token
	} else {
		os.Exit(66)
		return Token{}
	}
}

func (p *Parser) MatchToken(expectedToken Token) bool {
	token := p.PeekToken()
	if p.currentIndex >= len(p.tokens) {
		return false
	}
	if token.Type == expectedToken.Type { //&& token.Value == expectedToken.Value {
		return true
	}
	return false
}

type Node struct {
	Type     string
	Value    string
	Children []Node
}

func NewNode(type_ string, value string) Node {
	return Node{
		Type:  type_,
		Value: value,
	}
}

func (n *Node) AddChild(child Node) {
	n.Children = append(n.Children, child)
}

// <program>             ::= <statements>
// <statements>          ::= <statement> <statements> | ε
// <statement>           ::= <declaration>
//                         | <comment>
//                         | <if_statement>
//                         | <while_loop>
//                         | <print_statement>
//                         | <incrementdecrement>
// <declaration>         ::= "int" <identifier> "=" <expression> ";"
//                         | "bool" <identifier> "=" <boolean> ";"
// <comment>             ::= "//" <comment_text>
//                         | "/*" <comment_text> "*/"
// <if_statement>        ::= "if" "(" <expression> ")" <block>
//                           "else" <block>
// <while_loop>          ::= "while" "(" <expression> ")" <block>
// <block>				 ::= "{" <statements> "}"
// <print_statement>     ::= "print" <expression> ";"
// <incrementdecrement>  ::= <identifier> "++" ";"
//                         | <identifier> "--" ";"
// <expression>          ::= <integer> (">=" | ">" | "<=" | "<" | "==" | "!=" | "+" | "-" | "*" | "/" | "%" <expression>)*
//                         | <boolean> (">=" | ">" | "<=" | "<" | "==" | "!=" | "+" | "-" | "*" | "/" | "%" <expression>)*
//                         | <identifier> (">=" | ">" | "<=" | "<" | "==" | "!=" | "+" | "-" | "*" | "/" | "%" <expression>)*
// <boolean>             ::= "true"
//                         | "false"
// <identifier>          ::= [a-zA-Z_][a-zA-Z0-9_]*
// <integer>             ::= [0-9]+

func (p *Parser) Parse() Node {
	return p.ParseProgram()
}

func (p *Parser) ParseProgram() Node {
	root := NewNode("Program", "Program")

	statements := p.ParseStatements()
	root.AddChild(statements)

	return root
}

func (p *Parser) ParseStatements() Node {
	root := NewNode("Statements", "Statements")
	for p.MatchToken(Token{Type: "eof", Value: "eof"}) == false {
		statement := p.ParseStatement()
		root.AddChild(statement)
	}
	return root
}

func (p *Parser) ParseStatement() Node {
	root := NewNode("Statement", "Statement")
	if p.MatchToken(Token{Type: "if", Value: "if"}) {
		root.AddChild(p.ParseIfStatement())
	} else if p.MatchToken(Token{Type: "while", Value: "while"}) {
		root.AddChild(p.ParseWhileLoop())
	} else if p.MatchToken(Token{Type: "print", Value: "print"}) {
		root.AddChild(p.ParsePrintStatement())
	} else if p.MatchToken(Token{Type: "int", Value: "int"}) {
		root.AddChild(p.ParseDeclaration())
	} else if p.MatchToken(Token{Type: "bool", Value: "bool"}) {
		root.AddChild(p.ParseDeclaration())
	} else if p.MatchToken(Token{Type: "linecomment", Value: "linecomment"}) {
		root.AddChild(p.ParseLineComment())
	} else if p.MatchToken(Token{Type: "blockcomment", Value: "blockcomment"}) {
		root.AddChild(p.ParseBlockComment())
	} else if p.MatchToken(Token{Type: "identifier", Value: "identifier"}) {
		root.AddChild(p.ParseIncrementDecrement())
	} else {
		os.Exit(77)
		return Node{}
	}
	return root
}
func (p *Parser) ParseIfStatement() Node {
	root := NewNode("IfStatement", "IfStatement")
	p.ConsumeToken(Token{Type: "if", Value: "if"})
	p.ConsumeToken(Token{Type: "left_paren", Value: "("})
	root.AddChild(p.ParseExpression())
	p.ConsumeToken(Token{Type: "right_paren", Value: ")"})
	root.AddChild(p.ParseBlock())

	if p.MatchToken(Token{Type: "else", Value: "else"}) {
		p.ConsumeToken(Token{Type: "else", Value: "else"})
		root.AddChild(NewNode("ElseStatement", "ElseStatement"))
		root.AddChild(p.ParseBlock())
	}
	return root
}

func (p *Parser) ParseWhileLoop() Node {
	root := NewNode("WhileLoop", "WhileLoop")
	p.ConsumeToken(Token{Type: "while", Value: "while"})
	p.ConsumeToken(Token{Type: "left_paren", Value: "("})
	root.AddChild(p.ParseExpression())
	p.ConsumeToken(Token{Type: "right_paren", Value: ")"})
	root.AddChild(p.ParseBlock())
	return root
}

func (p *Parser) ParseBlock() Node {
	root := NewNode("Block", "Block")
	p.ConsumeToken(Token{Type: "left_brace", Value: "{"})
	for !p.MatchToken(Token{Type: "right_brace", Value: "}"}) {
		root.AddChild(p.ParseStatement())
	}
	p.ConsumeToken(Token{Type: "right_brace", Value: "}"})
	return root
}

func (p *Parser) ParsePrintStatement() Node {
	root := NewNode("PrintStatement", "PrintStatement")
	p.ConsumeToken(Token{Type: "print", Value: "print"})
	root.AddChild(p.ParseExpression())
	p.ConsumeToken(Token{Type: "semicolon", Value: ";"})
	return root
}

func (p *Parser) ParseDeclaration() Node {
	root := NewNode("Declaration", "Declaration")
	if p.MatchToken(Token{Type: "int", Value: "int"}) {
		root.AddChild(NewNode("Type", "int"))
		p.ConsumeToken(Token{Type: "int", Value: "int"})
	} else if p.MatchToken(Token{Type: "bool", Value: "bool"}) {
		root.AddChild(NewNode("Type", "bool"))
		p.ConsumeToken(Token{Type: "bool", Value: "bool"})
	}

	if !p.MatchToken(Token{Type: "identifier", Value: "identifier"}) {
		os.Exit(88)
	}
	root.AddChild(NewNode("Identifier", p.PeekToken().Value))
	p.ConsumeToken(Token{Type: "identifier", Value: "identifier"})

	if !p.MatchToken(Token{Type: "assign", Value: "assign"}) {
		os.Exit(99)
	}
	root.AddChild(NewNode("Assign", "assign"))
	p.ConsumeToken(Token{Type: "assign", Value: "assign"})

	root.AddChild(p.ParseExpression())

	p.ConsumeToken(Token{Type: "semicolon", Value: ";"})
	return root
}

func (p *Parser) ParseLineComment() Node {
	root := NewNode("LineComment", "LineComment")
	root.AddChild(NewNode("linecomment", p.PeekToken().Value))
	p.ConsumeToken(Token{Type: "linecomment", Value: "linecomment"})
	return root
}

func (p *Parser) ParseBlockComment() Node {
	root := NewNode("BlockComment", "BlockComment")
	root.AddChild(NewNode("blockcomment", p.PeekToken().Value))
	p.ConsumeToken(Token{Type: "blockcomment", Value: "blockcomment"})
	return root
}

func (p *Parser) ParseIncrementDecrement() Node {
	root := NewNode("IncrementDecrement", "IncrementDecrement")
	root.AddChild(NewNode("identifier", p.PeekToken().Value))
	p.ConsumeToken(Token{Type: "identifier", Value: "identifier"})
	if p.MatchToken(Token{Type: "increment", Value: "increment"}) {
		root.AddChild(NewNode("increment", "increment"))
		p.ConsumeToken(Token{Type: "increment", Value: "increment"})
	} else if p.MatchToken(Token{Type: "decrement", Value: "decrement"}) {
		root.AddChild(NewNode("decrement", "decrement"))
		p.ConsumeToken(Token{Type: "decrement", Value: "decrement"})
	}
	p.ConsumeToken(Token{Type: "semicolon", Value: ";"})
	return root
}

func (p *Parser) ParseExpression() Node {
	root := NewNode("Expression", "Expression")

	if p.MatchToken(Token{Type: "integer", Value: "integer"}) {
		root.AddChild(NewNode("integer", p.PeekToken().Value))
		p.ConsumeToken(Token{Type: "integer", Value: "integer"})
	} else if p.MatchToken(Token{Type: "identifier", Value: "identifier"}) {
		root.AddChild(NewNode("Identifier", p.PeekToken().Value))
		p.ConsumeToken(Token{Type: "identifier", Value: "identifier"})
	} else if p.MatchToken(Token{Type: "true", Value: "true"}) {
		root.AddChild(NewNode("True", p.PeekToken().Value))
		p.ConsumeToken(Token{Type: "true", Value: "true"})
	} else if p.MatchToken(Token{Type: "false", Value: "false"}) {
		root.AddChild(NewNode("False", p.PeekToken().Value))
	}

	if p.MatchToken(Token{Type: "less_equal", Value: "<="}) ||
		p.MatchToken(Token{Type: "less", Value: "<"}) ||
		p.MatchToken(Token{Type: "greater_equal", Value: ">="}) ||
		p.MatchToken(Token{Type: "greater", Value: ">"}) ||
		p.MatchToken(Token{Type: "equal", Value: "=="}) ||
		p.MatchToken(Token{Type: "not_equal", Value: "!="}) {

		root.AddChild(NewNode("Operator", p.PeekToken().Value))
		p.ConsumeToken(Token{Type: p.PeekToken().Type, Value: p.PeekToken().Value})
		root.AddChild(p.ParseExpression())
	}
	return root
}
func main() {
	fmt.Println(dataString + "\n====")

	reader := NewReader(dataString)
	scanner := NewScanner(reader)
	Tokens := make([]Token, 0)
	for {
		token := scanner.nextToken()
		fmt.Println(token)
		Tokens = append(Tokens, token)
		if token.Type == "eof" {
			break
		}
	}

	parser := NewParser(Tokens)
	root := parser.Parse()
	fmt.Println("====\n", root)
}
