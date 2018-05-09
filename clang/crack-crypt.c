// DES-based algorithm: crypt
#define _XOPEN_SOURCE
#include <unistd.h>
// char *crypt(const char *key, const char *salt);

#include <string.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    // The hashed password.
    string hashedPassword = argv[1];

    // Salt is a 2 character string [a-zA-Z0-9] used to
    // perturb the algorithm in 4096 different ways.

    // theSalt: is the first 2 characters of a hashed password:
    char theSalt[3];
    sprintf(theSalt, "%c%c", argv[1][0], argv[1][1]);
    // printf("test hash: %s\n", crypt("BBB", theSalt));

		// Dictionary Attack!
    char word[128];

    FILE* dict = fopen("/usr/share/dict/words", "r");
    if (dict == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    while (1)
    {
        if (fgets(word, 128, dict) == NULL) break;

        if (strncmp(crypt(strtok(word, "\n"), theSalt), hashedPassword, 14) == 0)
        {
            printf("%s\n", word);
            return 0;
        }
    }

    // Key is a user's typed password. We need to find key.
    char theKey[14];
    int result;

    // Test Keys:
    char firstChar[2];
    char secondChar[3];
    char thirdChar[4];
    char fourthChar[5];
    char fifthChar[6];

    // START ONE CHARACTER LOOP:
    for (int i = 'A'; i <= 'z'; i++)
    {
        if (i >= 91 && i <= 96)
        {
            i++;
        }
        else
        {
            // Convert i into char:
            sprintf(firstChar, "%c", i);
            sprintf(theKey, "%s", crypt(firstChar, theSalt));

            result = strncmp(hashedPassword, theKey, 14);

            if (result == 0)
            {
                printf("Found it!\n");
                printf("theKey: %s\n", firstChar);
                return 0;
            }
        }
    }
    // END ONE CHARACTER LOOP.
    printf("End of 1st loop.\n");


    // START TWO CHARACTER LOOP:
    for (int i = 'A'; i <= 'z'; i++)
    {
        if (i >= 91 && i <= 96)
        {
            i++;
        }
        else
        {
            // Second Iteration:
            for (int j = 'A'; j <= 'z'; j++)
            {
                if (j >= 91 && j <= 96)
                {
                    j++;
                }
                else
                {
                    // Convert i and j into char:
                    sprintf(secondChar, "%c%c", i, j);
                    sprintf(theKey, "%s", crypt(secondChar, theSalt));

                    result = strncmp(hashedPassword, theKey, 14);

                    if (result == 0)
                    {
                        printf("Found it!\n");
                        printf("theKey: %s\n", secondChar);
                        return 0;
                    }
                }
            }
        }
    }
    // END TWO CHARACTER LOOP.
    printf("End of 2nd loop.\n");


    // START THREE CHARACTER LOOP:
    for (int i = 'A'; i <= 'z'; i++)
    {
        if (i >= 91 && i <= 96)
        {
            i++;
        }
        else
        {
            // Second Iteration:
            for (int j = 'A'; j <= 'z'; j++)
            {
                if (j >= 91 && j <= 96)
                {
                    j++;
                }
                else
                {
                    // Third Iteration
                    for (int k = 'A'; k <= 'z'; k++)
                    {
                        if (k >= 91 && k <= 96)
                        {
                            k++;
                        }
                        else
                        {
                            // Convert i, j, and k into char:
                            sprintf(thirdChar, "%c%c%c", i, j, k);
                            sprintf(theKey, "%s", crypt(thirdChar, theSalt));

                            result = strncmp(hashedPassword, theKey, 14);

                            if (result == 0)
                            {
                                printf("Found it!\n");
                                printf("theKey: %s\n", thirdChar);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    // END THREE CHARACTER LOOP.
    printf("End of 3rd loop.\n");


    // START FOUR CHARACTER LOOP:
    for (int i = 'A'; i <= 'z'; i++)
    {
        if (i >= 91 && i <= 96)
        {
            i++;
        }
        else
        {
            // Second Iteration:
            for (int j = 'A'; j <= 'z'; j++)
            {
                if (j >= 91 && j <= 96)
                {
                    j++;
                }
                else
                {
                    // Third Iteration
                    for (int k = 'A'; k <= 'z'; k++)
                    {
                        if (k >= 91 && k <= 96)
                        {
                            k++;
                        }
                        else
                        {
                            // Fourth Iteration
                            for (int l = 'A'; l <= 'z'; l++)
                            {
                                if (l >= 91 && l <= 96)
                                {
                                    l++;
                                }
                                else
                                {
                                    // Convert i, j, k, and l into char:
                                    sprintf(fourthChar, "%c%c%c%c", i, j, k, l);
                                    sprintf(theKey, "%s", crypt(fourthChar, theSalt));

                                    result = strncmp(hashedPassword, theKey, 14);

                                    if (result == 0)
                                    {
                                        printf("Found it!\n");
                                        printf("theKey: %s\n", fourthChar);
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    // END FOUR CHARACTER LOOP.
    printf("End of 4th loop.\n");


    // START FIVE CHARACTER LOOP:
    for (int i = 'A'; i <= 'z'; i++)
    {
        if (i >= 91 && i <= 96)
        {
            i++;
        }
        else
        {
            // Second Iteration:
            for (int j = 'A'; j <= 'z'; j++)
            {
                if (j >= 91 && j <= 96)
                {
                    j++;
                }
                else
                {
                    // Third Iteration
                    for (int k = 'A'; k <= 'z'; k++)
                    {
                        if (k >= 91 && k <= 96)
                        {
                            k++;
                        }
                        else
                        {
                            // Fourth Iteration
                            for (int l = 'A'; l <= 'z'; l++)
                            {
                                if (l >= 91 && l <= 96)
                                {
                                    l++;
                                }
                                else
                                {
                                    // Fifth Iteration
                                    for (int m = 'A'; m <= 'z'; m++)
                                    {
                                        if (m >= 91 && m <= 96)
                                        {
                                            m++;
                                        }
                                        else
                                        {
                                            // Convert i, j, k, l, and m into char:
                                            sprintf(fifthChar, "%c%c%c%c%c", i, j, k, l, m);
                                            sprintf(theKey, "%s", crypt(fifthChar, theSalt));

                                            result = strncmp(hashedPassword, theKey, 14);

                                            if (result == 0)
                                            {
                                                printf("Found it!\n");
                                                printf("theKey: %s\n", fifthChar);
                                                return 0;
                                            }
                                        }
                                    } // End: Fifth Iteration
                                }
                            } // End: Fourth Iteration
                        }
                    } // End: Third Iteration
                }
            } // End: Second Iteration
        }
    } // End: First Iteration
    printf("End of 5th loop.\n");

    printf("No match found.");
    return 0;
}
