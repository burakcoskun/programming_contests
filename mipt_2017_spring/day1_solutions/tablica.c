
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int r, s;
char ts[200];
char *p[105][105];
char izr[105][105];
int br[105][105];

void rek (int i, int j)
{
 int k, red, stup;
 char *s = p[j][i];

 if (izr[j][i]) return;
 izr[j][i] = 1;
 if (s[0] != '=')
 {
  sscanf (s, "%d", &br[j][i]);
  return;
 }

 br[j][i] = 0;
 k = 1;
 for (;;)
 {
  if (s[k + 1] >= 'A' && s[k + 1] <= 'Z')
  {
     stup = (s[k] - 'A' + 1) * ('Z' - 'A' + 1) + s[k + 1] - 'A';
     k += 2;
  }
  else
  {
   stup = s[k] - 'A';
   ++k;
  }
  if (isdigit (s[k + 2]))
   red = (s[k] - '0') * 100 + (s[k + 1] - '0') * 10 + s[k + 2] - '0', k += 3;
  else if (isdigit (s[k + 1]))
   red = (s[k] - '0') * 10 + s[k + 1] - '0', k += 2;
  else red = s[k] - '0', ++k;
  --red;
  rek (stup, red);
  br[j][i] += br[red][stup];
  if (!s[k]) break;
  ++k;
 }
}

int main (void)
{
  FILE *fp = stdin;
 int i, j, l;

 fscanf (fp, "%d%d", &r, &s);
 for (j = 0; j < r; ++j)
     for (i = 0; i < s; ++i)
     {
      fscanf (fp, "%s", ts);
      l = strlen (ts);
      p[j][i] = malloc (l + 4);
      strcpy (p[j][i], ts);
      p[j][i][l] = 0;
      p[j][i][l + 1] = 'x';
      p[j][i][l + 2] = 'x';
      p[j][i][l + 3] = 'x';

      izr[j][i] = 0;
     }
 fclose (fp);
 for (j = 0; j < r; ++j)
     for (i = 0; i < s; ++i)
     {
      rek (i, j);
     }
 fp = stdout;
 for (j = 0; j < r; ++j)
     for (i = 0; i < s; ++i)
         fprintf (fp, "%d%c", br[j][i], (i == s - 1) ? '\n' : ' ');
 fclose (fp);
 return 0;
}
