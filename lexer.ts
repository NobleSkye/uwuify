// let x = 45 + (foo * bar)
// [ LetToken, identifierToken, EqualsToken, NumberToken ]


export enum TokenType {
    Number,
    Identifier,
    Equals,
    OpenParen, 
    CloseParen,
    BinaryOperator,
    Let,
}

const KEYWORDS: Record<string, TokenType> = {
    "let": TokenType.Let,

}


export interface Token {
    value: string;
    type: TokenType;
}

function isalpha (src: string) {
    return src.toUpperCase() != src.toLowerCase();
}

function isskipable (src: string) {
    return src == ' ' || src == '\n' || src == '\t';
} 


function isint(str: string) {
	const c = str.charCodeAt(0);
	const bounds = ["0".charCodeAt(0), "9".charCodeAt(0)];
	return c >= bounds[0] && c <= bounds[1];
}


function token (value = "", type: TokenType): Token{
    return { value, type};
}

export function tokenize (sourceCode: string): Token[] {

    const tokens = new Array<Token>();
    const src = sourceCode.split("");

    // Build each token until end of file
	while (src.length > 0) {
		// BEGIN PARSING ONE CHARACTER TOKENS
		if (src[0] == "(") {
			tokens.push(token(src.shift(), TokenType.OpenParen));
		} else if (src[0] == ")") {
			tokens.push(token(src.shift(), TokenType.CloseParen));
		} // HANDLE BINARY OPERATORS
		else if (src[0] == "+" || src[0] == "-" || src[0] == "*" || src[0] == "/") {
			tokens.push(token(src.shift(), TokenType.BinaryOperator));
		} // Handle Conditional & Assignment Tokens
		else if (src[0] == "=") {
			tokens.push(token(src.shift(), TokenType.Equals));
        } else {
            // Handles muticharacters tokens
            if (isint(src[0])) {
                let num = ""
                while (src.length > 0 && isint(src[0])) {
                    num += src.shift();
                }

                tokens.push(token(num, TokenType.Number));
            } else if (isalpha(src[0])) {
				let ident = ""; // foo -- user defined or // let -- keyword
				while (src.length > 0 && isalpha(src[0])) {
					ident += src.shift();
				}

                // check reserverd keywords
                const reserved = KEYWORDS[ident];
                if (reserved == undefined ) {
                    tokens.push(token(ident, TokenType.Identifier));
                } else {
                    tokens.push(token(ident, reserved));
                }
                
            } else if (isskipable(src[0])) {
                src.shift(); //Skips current character 
            } else  {
                console.error("Unreconized character found in source: ", src[0]);
                Deno.exit(1);
            }
        }
    }


    return tokens;
}


const source = await Deno.readTextFile("./test.txt");
for (const token of tokenize(source)) {
    console.log(token)
}