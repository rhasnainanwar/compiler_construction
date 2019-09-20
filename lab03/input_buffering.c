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

		// printf("%d %s\n", out_flag, buffer);

		begin = buffer;
		forward = buffer;

		while ((forward - buffer) <= out_flag) {
			if(isspace(*forward) || *forward == '\0'){
				// printf("Separator Reached\nBuffer at: %p\nBegin at: %p\nForward at: %p\n", (void*)buffer, (void*)begin, (void*)forward);
				// printf("Separator Reached\nBegin at: %ld\nForward at: %ld\n", begin-buffer, forward-buffer);

				if(!overflow_flag){
					str = (char *) malloc(BUFFER_SIZE); // used to maintain "string"
					memcpy(str, begin, (forward - begin));
				}
				else{
					dump = (char *) malloc(BUFFER_SIZE); // used to maintain "string"
					memcpy(dump, begin, (forward - begin));
					strcat(str, dump);
					overflow_flag = 0;
				}
				strcat(str, "\0");

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

		if((forward - buffer) > out_flag){
			str = (char *) malloc(BUFFER_SIZE); // used to maintain "string"
			memcpy(str, begin, (forward - begin));
			overflow_flag = 1;
		}
	}	
}