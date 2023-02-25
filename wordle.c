#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_ROUNDS 10

char *toUpper(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = toupper(str[i]);
        i++;
    }
    return str;
}

int main()
{

    int i, j, correct, misplaced;
    char myWord[MAX_WORD_LENGTH + 1];
    char guess[MAX_WORD_LENGTH + 1];
    char clue[MAX_WORD_LENGTH + 1];
    int wordLength, roundsLeft;
    char yeriyanlisharfler[10];
    char boylebirharfyokkardesim[10];
    int len;
    int len2 = 0;

    printf("Kelimeyi giriniz: ");
    scanf("%s", myWord);

    wordLength = strlen(myWord);
    toUpper(myWord);

    roundsLeft = MAX_ROUNDS;
    memset(clue, '_', wordLength);
    while (roundsLeft > 0 && strcmp(clue, myWord) != 0)
    {
        printf("\n%d tahmin hakkiniz kaldi.\n", roundsLeft);
        printf("Bir kelime tahmin ediniz (%d harf): ", wordLength);
        scanf("%s", guess);
        toUpper(guess);
        len2 = 0;
        correct = 0;
        misplaced = 0;
        for (i = 0; i < wordLength; i++)
        {
            if (guess[i] == myWord[i])
            {
                clue[i] = myWord[i];
                correct++;
            }
            else
            {
                for (j = 0; j < wordLength; j++)
                {
                    if (guess[i] == myWord[j])
                    {
                        misplaced++;
                        len = strlen(yeriyanlisharfler);
                        yeriyanlisharfler[len] = guess[i];
                        yeriyanlisharfler[len + 1] = '\0';
                    }
                    if (((j + 1) == wordLength) && misplaced == 0)
                    {
                        boylebirharfyokkardesim[len2] = guess[i];
                        boylebirharfyokkardesim[len2 + 1] = '\0';
                        len2++;
                    }
                }
            }
        }

        if (correct == wordLength)
        {
            printf("Tebrikler, kelimeyi dogru tahmin ettiniz!\n");
            return 0;
        }
        else
        {
            roundsLeft--;
            printf("%s \n", clue);
            printf("Yanlis konumda olan harfler: %s\n", yeriyanlisharfler);
            printf("Olmayan harfler: %s\n", boylebirharfyokkardesim);
            yeriyanlisharfler[0] = '\0';
            boylebirharfyokkardesim[0] = '\0';
        }
    }
}
