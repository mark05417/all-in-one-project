// Reader class
class Reader {
    constructor(str) {
        this.data = str;
        this.currPos = 0;
        this.dataLength = str.length;

    }
    nextChar() {
        if (this.currPos >= this.dataLength) {
            return -1; //end of stream
        }

        return this.data[this.currPos++];
    }
    //n is the number of characters to be retracted
    retract(n) {
        if (n == undefined) {
            n = 1;
        }

        this.currPos -= n;

        if (this.currPos < 0) {
            this.currPos = 0;
        }
    }
}

// Token class
class Token {
    constructor(type, text) {
        this.type = type;
        this.text = text;
    }
}

Token.tokens = {};
Token.tokens.EOS_TOKEN = 1; //end of stream
Token.tokens.COLON_TOKEN = Token.tokens.EOS_TOKEN + 1;
Token.tokens.SEMICOLON_TOKEN = Token.tokens.COLON_TOKEN + 1;
Token.tokens.LEFTPAREN_TOKEN = Token.tokens.SEMICOLON_TOKEN + 1;
Token.tokens.RIGHTPAREN_TOKEN = Token.tokens.LEFTPAREN_TOKEN + 1;
Token.tokens.LEFTBRACE_TOKEN = Token.tokens.RIGHTPAREN_TOKEN + 1;
Token.tokens.RIGHTBRACE_TOKEN = Token.tokens.LEFTBRACE_TOKEN + 1;
Token.tokens.MOD_TOKEN = Token.tokens.RIGHTBRACE_TOKEN + 1;
Token.backwardMap = {}; //for inverse look-up

for (var x in Token.tokens){
    Token.backwardMap[Token.tokens[x]] = x;
}

// Scanner class
class Scanner {
    constructor(reader) {
        this.reader = reader;
        this.currentToken = new Token(Token.tokens.EOS_TOKEN, "");
        this.currentLine = 0;
        this.currentState = 0;
    }
}

Scanner.START_STATE = 1; //start state

Scanner.prototype.makeToken = function (type, text){
    this.currentToken.type = type;
    this.currentToken.text = text;
    return type;
}