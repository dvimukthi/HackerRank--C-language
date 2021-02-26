//Querying the Document

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char**** get_document (char* text) 
{
    int dist, w_num, s_num, p_num;
    char *start, *word;
    char** sent;
    char*** para;
    char**** doc;
    
    doc=(char****)malloc(sizeof(char***));
    memset(doc, '\0', sizeof(char***));
    p_num=1;
    
    while(*text!='\0')
    {
        para=(char***)malloc(sizeof(char**));
        memset(para, '\0', sizeof(char**));
        s_num=1;
        
        while((*text!='\n')&&(*text!='\0'))
        {
            sent=(char**)malloc(sizeof(char*));
            memset(sent, '\0', sizeof(char*));
            w_num=1;
            
            while(*text!='.')
            {
                start=text;
                while((*text!=' ')&&(*text!='.')){text++;}
                
                dist=text-start;
                word=(char*)malloc(sizeof(char)*(dist+1));
                
                memcpy(word, start, dist);
                memset(word+dist, '\0', sizeof(char));
                
                sent=realloc(sent, sizeof(char*)*(w_num+1));
                *(sent+w_num-1)=word;
                *(sent+w_num)='\0';
                
                w_num++;
                if(*text==' ')text++;
            }
            
            para=realloc(para, sizeof(char**)*(s_num+1));
            *(para+s_num-1)=sent;
            *(para+s_num)='\0';
            s_num++;
            text++;
        }
        
        doc=realloc(doc, sizeof(char***)*(p_num+1));
        *(doc+p_num-1)=para;
        *(doc+p_num)='\0';
        p_num++;
        
        if(*text=='\n')text++;
    }
    
    return doc;  
}

char* kth_word_in_mth_sentence_of_nth_paragraph (char**** document, int k, int m, int n) 
{
    n--;m--;k--;
    
    return *(*(*(document+n)+m)+k);
}

char** kth_sentence_in_mth_paragraph (char**** document, int k, int m) 
{ 
    return document[m-1][k-1];
}

char*** kth_paragraph (char**** document, int k) 
{
    return document[k-1];
}


char* get_input_text() 
{	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++)
    {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) 
{
    printf("%s", word);
}

void print_sentence(char** sentence) 
{
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++)
    {
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) 
{
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) 
    {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) 
    {
        int type;
        scanf("%d", &type);

        if (type == 3)
        {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2)
        {
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else
        {
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        
        printf("\n");
    }     
}