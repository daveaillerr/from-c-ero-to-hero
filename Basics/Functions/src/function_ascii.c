#include <stdio.h>

void control_codes(void); // 0 - 31
void all_char(void); //  32 - 127

int main(){
	
	printf("\t\t\t\t---ASCII TABLE---\n");
	printf("\n\tDECIMAL\t\tSYMBOL/DESCRIPTION\n");
	
	control_codes();
	all_char();
	
	return 0;
}

void control_codes(void) // 0 - 31
{
    printf("	0	-	Null character\n"
           "	1	-	Start of Heading\n"
           "	2	-	Start of Text\n"
           "	3 	-	End of Text\n"
           "	4	-	End of Transmission\n"
           "	5	-	Enquiry\n"
           "	6	-	Acknowledge\n"
           "	7	- 	Bell\n"
           "	8 	- 	Backspace\n"
           "	9 	-	Horizontal Tab\n"
           "	10 	-	Line Feed\n"
           "	11 	-	Vertical Tabulation\n"
           "	12 	-	Form Feed\n"
           "	13 	-	Carriage Return\n"
           "	14 	-	Shift Out\n"
           "	15 	-	Shift In\n"
           "	16 	-	Data Link Escape\n"
           "	17 	-	Device Control One\n"
           "	18 	-	Device Control Two\n"
           "	19 	-	Device Control Three\n"
           "	20 	-	Device Control Four\n"
           "	21 	-	Negative Acknowledge\n"
           "	22 	- 	Synchronous Idle\n"
           "	23 	-	End of Transmission Block\n"
           "	24 	-	Cancel\n"
           "	25 	-	End of medium\n"
           "	26 	-	Substitute\n"
           "	27 	-	Escape\n"
           "	28 	-	File Separator\n"
           "	29 	-	Group Separator\n"
           "	30 	-	Record Separator\n"
           "	31	-	Unit Separator\n");
}

void all_char(void) //  32 - 127
{
	int i;
	printf("	32	-	Space\n");
	for (i = 33; i <= 126; i++){
		printf("	%d	-	%c\n", i, i);
	}
	printf("	127	-	Delete\n");
}