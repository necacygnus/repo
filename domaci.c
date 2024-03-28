#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
	FILE* fp;
	int a;
	int b[3];
	char a_c[8];
	int i = 0;

	char *str;
	char reg;
	int reg1;
	size_t num_of_bytes = 6;
	
	
while (1) {
//--------------------PETLJA KOJA TRI PUTA UPISUJE LEDOVKE------------------	
while (i < 3){
	a = rand() % 16;
	b[i] = a;
	sprintf(a_c, "%d", a);//Konverzija u string
	//puts(a_c);//Ispis u string

//-------------FUNKCIJA ZA UPIS LEDOVKI---------------------

	
	fp = fopen("/dev/led", "w");
	if (fp == NULL) {
		printf("Problem prilikom otvaranja\n");
		return -1;
}
	fputs(a_c, fp);
	if (fclose(fp)) {
		printf("Problem pri zatvaranju\n");
		return -1;
}
	usleep(700000);
	i++;
}

while (i >= 3) {
	fp = fopen("/dev/button","r");
	if (fp == NULL) {
		puts("Problem pri otvaranju fajla");
		return -1;
}
	str = (char *)malloc(num_of_bytes + 1);
	getline(&str, &num_of_bytes, fp);
	if (fclose(fp)) {
		puts("Problem pri zatvaranju fajla");
		return -1;
}
	reg = str[2];
	free(str);
	//a = *reg;
	sprintf(a_c, "%d", reg);
	//strcpy(a_c, reg);
	//fprintf(str,"%d\n",reg);
	//asprintf(&str,"%d",reg);
	//printf("%c",reg);
	//putchar();
	//fputs("Vrednost je: \n", a_c);
	puts(a_c);
	
	while(1);
	

}


//------------FUNKCIJA ZA ZATVARANJE LEDOVKI------------------
/*
	fp = fopen("/dev/led","w");
	if (fp == NULL) {
		printf("Problem pri otvaranju\n");
		return -1;
}
	fputs("0x00\n", fp);
	if (fclose(fp)) {
		printf("Problem pri zatvaranju\n");
		return -1;
}
	usleep(1000000);
*/
}
	
	
}
