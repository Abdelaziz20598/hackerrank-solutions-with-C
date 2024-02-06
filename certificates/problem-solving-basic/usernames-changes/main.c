#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** possibleChanges(int usernames_count, char** usernames) {
    char** result;
    result = (char**)malloc(usernames_count * sizeof(char*));
    printf("count: %d\n", usernames_count);
    for(int i = 0; i < usernames_count; i++){
        if(strlen(*(usernames + i)) <= 1){
                *(result + i) = (char**) malloc(3 * sizeof(char));
                *(result + i) = "NO";
        }
        else{
            for (int j = 0; j < strlen(*(usernames + i)); j++){
                if(*(usernames + j) > *(usernames + j + 1)){
                    *(result + i) = (char**) malloc(4 * sizeof(char));
                    *(result + i) = "YES";
                }
                else{
                    *(result + i) = (char**) malloc(3 * sizeof(char));
                    *(result + i) = "NO";
                }

            }
        }
    }
    return result;
}
int main()
{
    int max_limit = 15;
    printf("please enter the nu of users: ");
    int usernames_count = 1;
    scanf("%d", &usernames_count);
    char** usernames = malloc(usernames_count * sizeof(char*));
    printf("please enter the name of users:\n");
	for(int i = 0; i < usernames_count; i++)
        {
		*(usernames + i) = malloc(max_limit * sizeof(char));
		scanf("%s", *(usernames + i));
		*(usernames + i) = realloc(*(usernames + i), strlen(*(usernames + i)) + 1);
	}



    char** result = possibleChanges(usernames_count, usernames);

    for (int i = 0; i < usernames_count; i++) {
        printf("%s\n", *(result + i));
        }
    free(usernames);
    free(result);
    return 0;
}
