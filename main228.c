#include "lib.h"

int main(void)
{
	
	char *buf;
	size_t bufsize = 1024;
	int chara;
	int q = 0;
	char **doub;
	int qq = 0;
	char *simp;
	char **simpD;

	char *slash;
	//---
	//char *path = getPath();
	//---
	//char *path;
	
/*	buf = malloc(sizeof(char) * bufsize);
	if (!buf)
		return (0);
*/
	//buf = (char *)malloc(bufsize * sizeof(char));

	while (1)
	{
		if (isatty(0))
			write(1,"$ ",2);
		//chara = getline(&buf, &bufsize, stdin);

		buf = malloc(sizeof(char *) * bufsize);
		if (!buf)
			return (0);
		
		chara = getline(&buf, &bufsize, stdin);
		
		if (chara == -1)
			return (-1);
		
		if((buf[chara - 1]) == '\n')
			buf[chara - 1] = 0;
		//printf("input geted: %s\n", buf);	
	//AGREGAR FUNCION STRCMP
	/*	int t = _strcmp(buf, "EOF");
		
		if (t == 0)
			return (-1);
	*/

		q = qStrtok(buf);
		
		//doub = strD2(buf);
		//printf("compare: %d\n", t);
		//printf("cantidad de tokens: %d\n", q);
		doub = strD2(buf);
		
		for (int h = 0; h < q; h++)
			printf("doub[%d]: %s\n", h, doub[h]);

		//printf("%s\n", getPath());
		
		//-----------		
		simp = compEnv("PATH");

		qq = qStrtokPath(simp);

		//printf("EL PATH TIENE %d TOKENS\n", qq);

		simpD = strD2Path(simp);

		for (int gg = 0; simpD[gg]; gg++)
			printf("DP [%d]: %s\n", gg, simpD[gg]);
		//----
		

		slash = str_concat("/", doub[0]);
		
		concPath(simpD, slash);
		
		/* ACÁ EN REALIDAD NO HAY QUE IGUALARLO, SINO QUE HAY QUE CREAR UNA COPIA DE DOUB[0] EN SIMPD[qq], PARA ESO HAY QUE SABER EL TAMAÑO
		   DE DOUB[0] Y HACERLE MALLOC A SIMPD[QQ] CON ESE TAMÑO Y HACERLE UNA COPIA DE DOUB[0]
		
		int len0 = _strlen(doub[0]);

		simpD[qq] = malloc(sizeof(char) * (len0 + 1));
		if (!simpD[qq])
			return (-1);

		_strcpy(simpD[qq], doub[0]);

		simpD[qq][len0] = '\0';*/
		
		simpD[qq] = doub[0];
		
		//printf("SLASH: %s\n", slash);

		for (int kk = 0; simpD[kk]; kk++)
		{
		//	str_concat(simpD[kk], slash);
			printf("simpD[%d]: %s\n", kk, simpD[kk]);
		}
		//printf("%s\n", strD2Path(getPath())[2]);
		//printf("%s\n", doub[0]);
		

		executen(simpD, doub);

		//printf("Array: %s\n", str_concat(simpD[2], slash));
		
		
		//printf("%s\n", str_concat(strD2Path(getPath())[2], doub[0]));
	}
	return (0);
}
