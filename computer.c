/*
 * Daniel O'Connell
 * Assignment 3
 * computer.c
 *
 *  Created on: Mar 31, 2016
 */

#include <stdio.h>

int  compile( int *accumulator, int *instructionCounter, int *instructionRegister,
              int *operand,     int *operationCode,      int *wordMemory);
void *memset( void *str,        int c,                   size_t n);
int  strncmp( const char *str1, const char *str2,        size_t n);
int  execute( int *accumulator, int *instructionCounter, int *instructionRegister,
              int *operand,     int *operationCode,      int *wordMemory);
void datadump(int *accumulator, int *instructionCounter, int *instructionRegister,
              int *operand,     int *operationCode,      int *wordMemory);
void *calloc(size_t nmemb, size_t size);

int main (void){
	int accumulator = 0;
	int instructionCounter = 0;
	int instructionRegister = 0;
	int operand = 0;
	int operationCode = 0;
    int *wordMemory = (int *)calloc(100,sizeof(int));

    
	if(compile(&accumulator, &instructionCounter, &instructionRegister,
			   &operand, &operationCode, wordMemory) != 0){
				   return 1;
    }/* end if compile */
    
    stdin = fopen("/dev/tty", "r");
    if(execute(&accumulator, &instructionCounter, &instructionRegister,&operand, &operationCode, wordMemory) != 0){
	    return 1;
    } /*end if execute*/
	return 0;
}

int compile(int *accumulator, int *instructionCounter, int *instructionRegister,
		     int *operand, int *operationCode, int *wordMemory){
    char word[10];
	*accumulator = scanf("%d %s %d", instructionCounter, word, operand);
	while(*accumulator != EOF){
		if(*accumulator != 3){
			printf("Segmentation Fault In Compile\n\n");
			return 1;
		}

		if(strncmp(word,"READ",5) == 0){
		    if(*operand > 99){
		        printf("Word Overflow\n\n");
		        return 1;
		    }
		    *instructionRegister = 1000 + *operand;
		    wordMemory[*instructionCounter] = *instructionRegister;
		}

		if(strncmp(word,"WRIT",5) == 0){
		    if(*operand > 99){
		        printf("Segmentation Fault In Compile\n\n");
		        return 1;
		    }
		    *instructionRegister = 1100 + *operand;
		    wordMemory[*instructionCounter] = *instructionRegister;
		}

		if(strncmp(word,"PRNT",5) == 0){
		    if(*operand > 99){
		        printf("Segmentation Fault In Compile\n\n");
		        return 1;
		    }
		    *instructionRegister = 1200 + *operand;
		    wordMemory[*instructionCounter] = *instructionRegister;
		}

		if(strncmp(word,"LOAD",5) == 0){
		    if(*operand > 99){
		        printf("Segmentation Fault In Compile\n\n");
		        return 1;
		    }
		    *instructionRegister = 2000 + *operand;
		    wordMemory[*instructionCounter] = *instructionRegister;
		}

		if(strncmp(word,"STOR",5) == 0){
		    if(*operand > 99){
		        printf("Segmentation Fault In Compile\n\n");
		        return 1;
		    }
		    *instructionRegister = 2100 + *operand;
		    wordMemory[*instructionCounter] = *instructionRegister;
		}

		if(strncmp(word,"SET",4) == 0){
	         if(*operand > 9999){
	             printf("Segmentation Fault In Compile\n\n");
	             return 1;
	         }
	         *instructionRegister = *operand;
	         wordMemory[*instructionCounter] = *instructionRegister;
		}

		if(strncmp(word,"ADD",4) == 0){
		    if(*operand > 99){
		        printf("Segmentation Fault In Compile\n\n");
		        return 1;
		    }
		    *instructionRegister = 3000 + *operand;
		    wordMemory[*instructionCounter] = *instructionRegister;
		}

		if(strncmp(word,"SUB",4) == 0){
            if(*operand > 99){
                printf("Segmentation Fault In Compile\n\n");
                return 1;
            }
            *instructionRegister = 3100 + *operand;
            wordMemory[*instructionCounter] = *instructionRegister;
        }

		if(strncmp(word,"DIV",4) == 0){
            if(*operand > 99){
                printf("Segmentation Fault In Compile\n\n");
                return 1;
            }
            *instructionRegister = 3200 + *operand;
            wordMemory[*instructionCounter] = *instructionRegister;
        }

		if(strncmp(word,"MULT",5) == 0){
            if(*operand > 99){
                printf("Segmentation Fault In Compile\n\n");
                return 1;
            }
            *instructionRegister = 3300 + *operand;
            wordMemory[*instructionCounter] = *instructionRegister;
        }

		if(strncmp(word,"MOD",4) == 0){
            if(*operand > 99){
                printf("Segmentation Fault In Compile\n\n");
                return 1;
            }
            *instructionRegister = 3400 + *operand;
            wordMemory[*instructionCounter] = *instructionRegister;
        }

		if(strncmp(word,"BRAN",5) == 0){
            if(*operand > 99){
                printf("Segmentation Fault In Compile\n\n");
                return 1;
            }
            *instructionRegister = 4000 + *operand;
            wordMemory[*instructionCounter] = *instructionRegister;
        }

		if(strncmp(word,"BRNG",5) == 0){
            if(*operand > 99){
                printf("Segmentation Fault In Compile\n\n");
                return 1;
            }
            *instructionRegister = 4100 + *operand;
            wordMemory[*instructionCounter] = *instructionRegister;
        }

		if(strncmp(word,"BRZR",5) == 0){
		    if(*operand > 99){
                printf("Segmentation Fault In Compile\n\n");
                return 1;
            }
            *instructionRegister = 4200 + *operand;
            wordMemory[*instructionCounter] = *instructionRegister;
		}

		if(strncmp(word,"HALT",5) == 0){
            if(*operand > 99){
                printf("Segmentation Fault In Compile\n\n");
                return 1;
            }
            *instructionRegister = 9900 + *operand;
            wordMemory[*instructionCounter] = *instructionRegister;
            *operationCode = 1;
        }

		memset(word,0,4);
		*accumulator = scanf("%d %s %d", instructionCounter, word, operand);
	}/* end while */

	if(*operationCode != 1){
	    printf("No-HAULT Error Occurred\n\n");
	    return 1;
	}

	*operationCode = 0;
	return 0;
}

int execute(int *accumulator, int *instructionCounter, int *instructionRegister,
            int *operand, int *operationCode, int *wordMemory){

    if((*instructionCounter > 99) || (*instructionCounter < 0)){
        printf("Segmentation Fault In Compile\n\n");
        datadump(accumulator, instructionCounter, instructionRegister, operand, operationCode, wordMemory);
        return 1;
    }
    *instructionCounter = 0;
    while(*instructionCounter < 100){
        *instructionRegister = wordMemory[*instructionCounter];
        *operationCode = *instructionRegister/100;
        *operand = *instructionRegister % 100;
        if(*operand > 99 || *operand < 0){
            printf("Fault In Compile\n\n");
            datadump(accumulator, instructionCounter, instructionRegister, operand, operationCode, wordMemory);
            return 1;
        }
        /*
         * READ
         * Retrieve a value from the user and places it in the given address.
         */
        if(*operationCode == 10){
            scanf("%d",accumulator);
            if(*accumulator > 9999 || *accumulator < -9999){
                printf("Word overflow\n\n");
                return 1;
            }
            else{
                wordMemory[*operand] = *accumulator;
                *accumulator = 0;
            }

        }/*end if READ*/
        /*
         * WRIT
         * Output a word from the given address to the terminal.
         */
        else if(*operationCode == 11){
        	printf("%d",wordMemory[*operand]);
        }/*end if writ*/

        /*
         * PRNT
         * Outputs a string starting at the given address,
         * continue outputting till NULL is reached.
         */
        else if(*operationCode == 12){
            *operationCode = wordMemory[*operand];
            while(*operationCode%100 != 0 && *operationCode/100 != 0){
                if(*operationCode/100 != 10){
                    printf("%c",*operationCode/100);
                }
                if(*operationCode%100 != 10){
                    printf("%c",*operationCode%100);
                }
                else if(*operationCode/100 == 10 || *operationCode%100 == 10){
                    printf("\n");
                }
                *operand +=1;
                *operationCode = wordMemory[*operand];
            }

        }/*end if prnt*/

        /*
         * LOAD
         * Load a word from the given memory address into the accumulator.
         */
        else if(*operationCode == 20){
        	*accumulator = wordMemory[*operand];

        }/*end if load*/

        /*
         * STOR
         * Store the word in the accumulator into the given address.
         */
        else if(*operationCode == 21){
        	wordMemory[*operand] = *accumulator;
        }/*end if stor*/

        /*
         * SET
         * Stores the given word into the preceding address
         */
        else if(*operationCode == 22){
            printf("set found\n\n");
        }/*end if set*/

        /*
         * ADD
         * Adds the word at the given address to the accumulator.
         */
        else if(*operationCode == 30){
            *accumulator = *accumulator + wordMemory[*operand];
            if(*accumulator > 9999 || *accumulator < -9999){
                printf("Error when adding\n\n");
                datadump(accumulator, instructionCounter, instructionRegister, operand, operationCode, wordMemory);
                return 1;
            }
        }/*end if add*/

        /*
         * SUB
         * Adds the word at the given address to the accumulator.
         */
        else if(*operationCode == 31){
            *accumulator = *accumulator - wordMemory[*operand];
            if(*accumulator > 9999 || *accumulator < -9999){
                printf("Error when subtracting\n\n");
                datadump(accumulator, instructionCounter, instructionRegister, operand, operationCode, wordMemory);
                return 1;
            }
        }/*end if sub*/

        /*
         * DIV
         * Divides the word at the given address to the accumulator.
         */
        else if(*operationCode == 32){
            *accumulator = *accumulator / wordMemory[*operand];
            if(*accumulator > 9999 || *accumulator < -9999){
                printf("Error when dividing\n\n");
                datadump(accumulator, instructionCounter, instructionRegister, operand, operationCode, wordMemory);
                return 1;
            }
        }/*end if div*/

        /*
         * MULT
         * Multiplies the word at the given address to the accumulator.
         */
        else if(*operationCode == 33){
            *accumulator = *accumulator * wordMemory[*operand];
            if(*accumulator > 9999 || *accumulator < -9999){
                printf("Error when multiplying\n\n");
                datadump(accumulator, instructionCounter, instructionRegister, operand, operationCode, wordMemory);
                return 1;
            }
        }/*end if mult*/

        /*
         * MOD
         * Mods the word at the given address to the accumulator.
         */
        else if(*operationCode == 34){
            *accumulator = *accumulator % wordMemory[*operand];
            if(*accumulator > 9999 || *accumulator < -9999){
                printf("Error when finding remainder\n\n");
                datadump(accumulator, instructionCounter, instructionRegister, operand, operationCode, wordMemory);
                return 1;
            }
        }/*end if mod*/

        /*
         * BRAN
         * Execution jumps to the given memory location.
         */
        else if(*operationCode == 40){
        	*instructionCounter = *operand - 1;
        }/*end if BRAN*/

        /*
         * BRNG
         * Execution jumps to the given memory location if the accumulator is negative.
         */
        else if(*operationCode == 41){
            if(*accumulator < 0){
                *instructionCounter = *operand;
            }
        }/*end if BRNG*/

        /*
         * BRZR
         * Execution jumps to the given memory location if the accumulator is zero.
         */
        else if(*operationCode == 42){
            if(accumulator == 0){
                *instructionCounter = *operand;
            }
        }/*end if BRZR*/

        /*
         * HALT
         * Terminates execution, no address given, value of 99 is standard, also prints datadump.
         */
        else if(*operationCode == 99){
            datadump(accumulator, instructionCounter, instructionRegister, operand, operationCode, wordMemory);
            return 0;
        }/*end if HALT*/

        else{
            printf("Unknown Command\n\n");
            datadump(accumulator, instructionCounter, instructionRegister, operand, operationCode, wordMemory);
            return 1;
        }
        *instructionCounter = *instructionCounter + 1;
    }/*end while*/
    return 0;
}/*end execute*/

void datadump(int *accumulator, int *instructionCounter, int *instructionRegister, int *operand,
              int *operationCode, int *wordMemory){

    printf("REGISTER:\n");
    if(*accumulator >= 0){
        printf("accumulator:%24s%d\n","+",*accumulator);
    }
    else{
        printf("accumulator:%24d\n",*accumulator);
    }

    printf("instructionCounter:%15s%02d\n","",*instructionCounter);

    if(*instructionRegister >= 0){
        printf("instructionRegister:%12s%04d\n","+",*instructionRegister);
    }
    else{
        printf("instructionRegister:%12d\n",*instructionRegister);
    }

    printf("operationCode:%20s%02d\n","",*operationCode);
    printf("operand:%26s%02d\n","",*operand);
    printf("MEMORY:\n");
    printf("%8s%6s%6s%6s%6s%6s%6s%6s%6s%6s","0","1","2","3","4","5","6","7","8","9");
    printf("\n");
    *instructionRegister = 0;
    for(*operand = 0; *operand < 10; ){
        printf("%2d", *operand*10);

        for(*operationCode = 0; *operationCode < 10; ){
            if(wordMemory[*instructionRegister] >= 0){
                printf("%s+%04d", "",wordMemory[*instructionRegister]);
            }
            else{
                printf("%s%04d","",wordMemory[*instructionRegister]);
            }
            *operationCode = *operationCode + 1;
            *instructionRegister = *instructionRegister + 1;
        }
        printf("\n");
        *operand = *operand + 1;
    }
}

