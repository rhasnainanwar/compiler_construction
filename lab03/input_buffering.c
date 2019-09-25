#include "utils.c"

void single_buffer(FILE* fp){
	char buffer[BUFFER_SIZE];
	int out_flag = 0, temp, overflow_flag = 0;
	char *begin, *forward; // iterator
	char *str, *dump; // used to store "string"

	while(1) {
		out_flag = fill_buffer(fp, buffer);
		if(!out_flag)
			break;

		begin = buffer;
		forward = buffer;

		while ((forward - buffer) <= out_flag) {
			if(isspace(*forward) || *forward == '\0'){

				if(!overflow_flag){
					str = (char *) malloc(BUFFER_SIZE);
					memcpy(str, begin, (forward - begin));
				}
				else{
					dump = (char *) malloc(BUFFER_SIZE);
					memcpy(dump, begin, (forward - begin));
					strcat(str, dump);
					overflow_flag = 0;
				}
				strcat(str, "\0"); // make the input string-like

				if(strlen(str) == 0){
					forward++;
					begin = forward;
					continue;
				}

				if(strlen(str) > 1 && isidentifier(str))
					printf("%s is an identifier.\n", str);
				else if(temp = atoi(str))
					printf("%d is a constant.\n", temp);
				else if(strlen(str) == 1 && isop(*(forward-1)))
					printf("%c is an operator.\n", *(forward-1));

				begin = forward+1;
			}
			forward++;
		}

		if((forward - buffer) > out_flag){ // buffer end
			str = (char *) malloc(BUFFER_SIZE);
			memcpy(str, begin, (forward - begin));
			overflow_flag = 1;
		}
	}	
}


void buffer_pair(FILE* fp){
	char* buffer = (char *) malloc(BUFFER_SIZE*2);
	int current_buffer_half = 1, last = 0, cont = 1, temp, overflow_flag = 0;
	char *begin, *forward; // iterator
	char *str, *dump; // used to store "string"

	do {
		current_buffer_half = fill_buffer_pair(fp, buffer, current_buffer_half);

		begin = buffer+current_buffer_half*BUFFER_SIZE;
		forward = buffer+current_buffer_half*BUFFER_SIZE;

		while (*forward != '\0' && *forward != SENTINEL) {
			if(isspace(*forward)){

				if(!overflow_flag){
					str = (char *) malloc(BUFFER_SIZE);
					memcpy(str, begin, (forward - begin));
				}
				else{
					dump = (char *) malloc(BUFFER_SIZE);
					memcpy(dump, begin, (forward - begin));
					strcat(str, dump);
					overflow_flag = 0;
				}

				if(strlen(str) == 0){
					forward++;
					begin = forward;
					continue;
				}

				if(strlen(str) > 1 && isidentifier(str))
					printf("%s is an identifier.\n", str);
				else if(temp = atoi(str))
					printf("%d is a constant.\n", temp);
				else if(strlen(str) == 1 && isop(*(forward-1)))
					printf("%c is an operator.\n", *(forward-1));

				begin = forward+1;
			}
			forward++;
		}
		if(last){
			last = 0;
			cont = 0;
		}
		else if(*forward == '\0'){
			last = 1;
			overflow_flag = 1;
		}
		else if(*forward == SENTINEL){
			str = (char *) malloc(BUFFER_SIZE);
			memcpy(str, begin, (forward - begin));
			overflow_flag = 1;
		}

	} while(cont || last);

}