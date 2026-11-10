typedef enum {
    TOKEN_SPECIAL,
    TOKEN_DATA,
    TOKEN_OPERATOR,
    TOKEN_ERROR,
    TOKEN_IDENT,
    TOKEN_EOF
} ActType;

typedef struct
{
    ActType type;
    char lexeme[256];
    int line;
    int colum;
} Token;
