#include<stdio.h> 
void dollarize(char arr[], int dim);
int main() {
	char arr[11] = { 'h','e','l','l','o',' ','w','o','r','l','d' };
	dollarize(arr, 11);
	printf("%s\n", arr);
}
void dollarize(char arr[], int dim) {
	int i; for (i = 0; i < dim; i++)
		switch (arr[i]) {
		case'a':case'e':case'i':case'o':case'u': case'A':case'E':case'I':case'O':case'C':
			arr[i] = '$';
		} /*ALTERNATIVA:
		  If((arr[i]=='a')||(arr[i]=='e')||(arr[i]=='i')||(arr[i]=='o') ||
		  (arr[i]=='u')||(arr[i]=='A')||(arr[i]=='E') ||(arr[i]=='I')||
		  (arr[i]=='O')||(arr[i]=='U')) arr[i]='$';
		  */
}