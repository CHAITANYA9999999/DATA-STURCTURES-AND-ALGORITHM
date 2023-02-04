#include <stdio.h>
#include <string.h>

int* findLPS(char *pat, int *lps, int m)
{
    int count = 0, i = 1;
    lps[0] = 0;

    while (i < m)
    {
        if (pat[i] == pat[count])
        {
            lps[i++] = ++count;
        }
        else
        {
            lps[i++] = 0;
            count = 0;
        }
    }
    return (int*)&lps;
}

void kmpAlgo(char *txt, char *pat)
{
    int n, m, i, j;
    n = strlen(txt);
    m = strlen(pat);
    int lps[m];
    printf("%d%d", m, n);

    for (i = 0; i < m; i++)
    {
        lps[i] = 0;
    }
    *lps = findLPS(pat, lps, m);
    printf("\n LPS ARRAY IS: %s\n");
    for (i = 0; i < m; i++)
    {
        printf("%d ", lps[i]);
    }

    i = 0;
    j = 0;

    while (i < n)
    {

        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            j = lps[j - 1];
        }
    }
    if (j == m)
    {
        printf("We found the pattern at index %d\n", i - j);
        j=0;
    }
}

int main()
{
    char txt[] = "onionions";
    // char pat[] = "onion";
    char pat[] = "aaabaaa";
    for(int i = 0; i < sizeof(pat); i++){
        printf("%d", pat[i]);
    }

    kmpAlgo(txt, pat);
}