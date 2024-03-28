#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
	FILE* fp;
	int a;
	int b[3];
	int c[3];
	char a_c[8], a_c2[8], a_c3[8], a_c4[8], a_c5[8];
	int i = 0;
	char pom[8];
	//unsigned char prvo[8] = {"0", "1", "2", "4", "8", "4", "2", "1"};
	//unsigned char drugo[6] = {"f", "0", "f", "0", "f", "0"};

	char *str;
	char sw1, sw2, sw3, sw4;
	char reg_1, reg_2, reg_3, reg_4;
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

while (i >= 3 && i < 6) {
//---------------------------UCITAVANJE PREKIDACA---------------------------
while (reg_4 == 0) {

fp = fopen("/dev/switch","r");
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
	sw1 = str[2] - 48;
	sw2 = str[3] - 48;
	sw3 = str[4] - 48;
	sw4 = str[5] - 48;
	free(str);
	//a = *reg;
	c[i-3] = sw1 * 8 + sw2 * 4 + sw3 * 2 + sw4 * 1;

	sprintf(a_c, "%d", sw1);
	sprintf(a_c2, "%d", sw2);
	sprintf(a_c3, "%d", sw3);
	sprintf(a_c4, "%d", sw4);
	sprintf(a_c5, "%d", c[i-3]);
	//strcpy(a_c, reg);
	//fprintf(str,"%d\n",reg);
	//asprintf(&str,"%d",reg);
	//printf("%c",reg);
	//putchar();
	//fputs("Vrednost je: \n", a_c);
	puts(a_c);
	puts(a_c2);
	puts(a_c3);
	puts(a_c4);
	puts(a_c5);
	puts("\n");
	




//--------------------------UCITAVANJE TASTERA--------------------------
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
	//reg_1 = str[2];
	//reg_2 = str[3];
	//reg_3 = str[4];
	reg_4 = str[5] - 48;
	free(str);
	//a = *reg;
	//sprintf(a_c, "%d", reg_1);
	//sprintf(a_c2, "%d", reg_2);
	//sprintf(a_c3, "%d", reg_3);
	sprintf(a_c4, "%d", reg_4);
	//strcpy(a_c, reg);
	//fprintf(str,"%d\n",reg);
	//asprintf(&str,"%d",reg);
	//printf("%c",reg);
	//putchar();
	//fputs("Vrednost je: \n", a_c);
	//puts(a_c);
	//puts(a_c2);
	//puts(a_c3);
	puts(a_c4);
	puts("\n");

	sleep(1);
	
	if (reg_4 == 1) {
		reg_4 = 0;
		i++;
}
if (i == 6) reg_4 = 1;
}	
//sprintf(pom, "%d", i);
//puts(pom);
}

if (b[0] == c[0] && b[1] == c[1] && b[2] == c[2]) {
	puts("tacno");
	/*for (int i = 0; i++; i < 7){
	fp = fopen("/dev/led", "w");
	if (fp == NULL) {
		printf("Problem prilikom otvaranja\n");
		return -1;
}
	fputs(prvo[i], fp);
	if (fclose(fp)) {
		printf("Problem pri zatvaranju\n");
		return -1;
}
	usleep(250000);
}
	*/
}
else puts("netacno");
	
/*for (int i = 0; i++; i < 5){
fp = fopen("/dev/led", "w");
	if (fp == NULL) {
		printf("Problem prilikom otvaranja\n");
		return -1;
}
	fputs(drugo[i], fp);
	if (fclose(fp)) {
		printf("Problem pri zatvaranju\n");
		return -1;
}
	usleep(330000);
}
*/
sleep(5);
i = 0;
reg_4 = 0;
	
//----------------------------------ZAVRSNE DIODE------------------------------
for (int i = 0; i++; i < 7){
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
