typedef struct block{
        char * w;
        struct block * next;
}block;

char * getCharBlock();
int chunknum(char *text);
block * createblocks(int num);
void fillblocks(char * text, block * first);
void printIt(block* first);
void pushblock(block* first, block *next);
