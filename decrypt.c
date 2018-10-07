#include <stdio.h>
#include <string.h>

int matchd(char p[7], char b[][7])
{
	for(int i = 0; i < 64; i++)
	{
		if(strcmp(p, b[i]) == 0)
		{
			return i;
		}
	}
}

int decrypt()
{
	char a[64];
	char b[64][7];
	
	strcpy( b[0], "000000");//1
	strcpy( b[1], "100000");
	strcpy( b[2], "010000");
	strcpy( b[3], "001000");
	strcpy( b[4], "000100");
	strcpy( b[5], "000010");
	strcpy( b[6], "000001");
//////////////////////////////////////6
	strcpy( b[7], "010001");
	strcpy( b[8], "001001");
	strcpy( b[9], "000101");

	strcpy(	b[10], "110000");
	strcpy(	b[11], "101000");
	strcpy(	b[12], "100100");
	strcpy(	b[13], "100010");
	strcpy(	b[14], "011000");
	strcpy(	b[15], "010100");
	strcpy(	b[16], "010010"); 
///////////////////////////////////////10
	strcpy(	b[17], "000111");
	strcpy(	b[18], "100011");
	strcpy(	b[19], "010011");
	strcpy(	b[20], "001011");
	strcpy(	b[21], "110001");
	strcpy(	b[22], "011001");
	strcpy(	b[23], "001101");
	strcpy(	b[24], "010011");

	strcpy( b[25], "111000");
	strcpy( b[26], "110100");
	strcpy( b[27], "110010");
	strcpy( b[28], "101100");
	strcpy( b[29], "101010");
	strcpy( b[30], "011100");
	strcpy( b[31], "011010");
///////////////////////////////////////15
	strcpy( b[32], "001110");//16
	strcpy( b[33], "000011");//11
	strcpy( b[34], "000110");//12
	strcpy( b[35], "001100");//14
	strcpy( b[36], "100001");//13
	strcpy( b[37], "101001");//17
	strcpy( b[38], "100101");//18

	strcpy( b[39], "010101");//19
	strcpy( b[40], "101011");//20
	strcpy( b[41], "001010");//15

	strcpy( b[42], "001111");
	strcpy( b[43], "100111");
	strcpy( b[44], "010111");
	strcpy( b[45], "110011");
	strcpy( b[46], "011011");
	strcpy( b[47], "110101");
	strcpy( b[48], "101011");
	strcpy( b[49], "111001");
	strcpy( b[50], "011101");
	strcpy( b[51], "101101");

	strcpy( b[52], "111010");
	strcpy( b[53], "110110");
	strcpy( b[54], "101110");
	strcpy( b[55], "011110");
	strcpy( b[56], "111100");	

	strcpy( b[57], "011111");
	strcpy( b[58], "111110");
	strcpy( b[59], "111011");
	strcpy( b[60], "111101");
	strcpy( b[61], "101111");
	strcpy( b[62], "110111");
	strcpy( b[63], "111111");

	char code[1024];

	int i,k,j,l;
	for(i=0;i<62;i++)
		{	
			a[0]='A';a[26]='a';a[52]='0';
			for(j = 0; j< 26; j++)
			 		a[j]=a[0]+ j;
			for(k=26;k<52;k++)
					a[k]=a[26] + (k-26);
			for(l=52;l<62;l++)
					a[l]=a[52]+(l-52);

		}
		a[62]='$';
		a[63]='#';

	int tok;
	printf("Enter the token of your account: ");
	scanf("%d", &tok);

	int end, loop;
    char tstr[1000];
    FILE *f = fopen("logfile.txt", "r");

    for(end = loop = 0; loop < tok; ++loop)
    {
        if(0 == fgets(tstr, sizeof(tstr), f)){//include '\n'
            end = 1;//can't input (EOF occured)
            break;
        }
    }
       
    fclose(f);
	printf("%s\n", tstr);
    for(int i = 0; i < (strlen(tstr)-1); i++)
    {
    	if(tstr[i] == '0')
    		code[i] = '1';
    	else if(tstr[i] == '1')
    		code[i] = '0';
    }
    printf("%s\n", code);
	
	int ind[(strlen(code)/6)];
	char tc[7];
	for(int i = 0, k = 0; i < strlen(code); i+=6, k++)
	{
		for(int j = i, t = 0; j < i + 6; j++, t++)
		{
			tc[t] = code[j];
		}
		tc[6] = '\0';
		ind[k] = matchd(tc, b);
		//printf("%s\n", tc);
	}
	for (int i = 0; i < (strlen(tstr)/6); i++)
		printf("%d\n", ind[i]);
	
	for(int i = 0; i < (strlen(code)/6); i++)
		printf("%c", a[ ind[i] ]);
	
	printf("\n");
		printf("\n"); // Stops the output from being on the same line as the prompt


    

    char opt[50];
    printf("0 to go to menu.\n");
    while(1)
    {
        printf("> ");
        scanf(" %s",opt);
        int l = strlen(opt);
        if (l == 1)
        {
            if (opt[0] == '0')
            {
                return 0;
            }
            else
            {
                printf("Invalid Input.\n");
            }
        }
        
        else
            {
                printf("Invalid Input.\n");
            }
    }
    return 0;
}
