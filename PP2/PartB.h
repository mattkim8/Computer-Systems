typedef struct word{
        char * w;
        int frequency;
        int * lineNumers;  //this is a dynamically allocated list of int representing the line numbers
                            //in which the word appears
        // int numberOfLines;
        //this is the number of lines in which the word appears (you need this to realloc space for lineNumers
        struct word *next; //points to next word in the linked list
}word_t;


char * getPattern();
word_t *freq(char * text, word_t* root);
word_t* newword(char * text);
int isStop(char *line);
void mostfrequent(word_t *root);
