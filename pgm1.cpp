#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int no_of_schemas = 0;
struct schemas
{
	//description
	char **attributes;
	int *datatypes;
	//data
	int *intdata;
	char **chardata;
	float *floatdata;
	//count
	int ints;
	char chars;
	int cols;
};
char *schemanames[10];
struct schemas **disk = NULL;
int **fp = (int**)malloc(sizeof(int*));
fp[0] = (int*)malloc(sizeof(int) * 2);
fp[0][0] = fp[0][1] = 0;
void merge1(int *p, int idx, char *filename)
{
	FILE *fp;
	int count_columns = 0;
	int num = 0, k = 0;
	int i = p[0], j = p[1];
	char c;
	char read[80];
	printf("hwer");

	fp = fopen(filename, "r");
	do
	{

		if (feof(fp))break;
		c = fgetc(fp);
		if (c == ',' || c == '\n')
		{

			read[k] = '\0';
			k = 0;
			if (disk[idx]->datatypes[count_columns] == 1)
			{
				disk[idx]->intdata = (int*)realloc(disk[idx]->intdata, sizeof(int)*(p[0] + 1));
				disk[idx]->intdata[p[0]] = 0;
				disk[idx]->intdata[p[0]] = atoi(read);
				//		printf("%d ", store[idx]->intdata[p[0]]);
				p[0]++;
			}
			if (disk[idx]->datatypes[count_columns] == 2)
			{
				disk[idx]->chardata = (char**)realloc(disk[idx]->chardata, sizeof(char*)*(p[1] + 1));
				disk[idx]->chardata[p[1]] = (char*)malloc(sizeof(char) * 50);
				strcpy((disk[idx]->chardata[p[1]]), read);
				//	printf("%s ", store[idx]->chardata[p[1]]);

				p[1]++;
			}
			if (c == '\n')
				count_columns = 0;
			else
				count_columns++;

		}
		else
		{
			read[k++] = c;
		}
	} while (1);

	fclose(fp);

}
void create_schema(char *schema)
{
	int coutn_of_attr = 0;
	char type[10], name[10], schema[10];
	disk = (schemas **)realloc(disk, sizeof(schemas*)*(no_of_schemas + 1));
	disk[no_of_schemas] = (schemas *)malloc(sizeof(schemas));
	strcpy(schemanames[no_of_schemas], schema);
	disk[no_of_schemas]->ints = 0;
	disk[no_of_schemas]->chars = 0;
	disk[no_of_schemas]->datatypes = (int*)malloc(sizeof(int));
	disk[no_of_schemas]->attributes = (char **)malloc(sizeof(char *));
	disk[no_of_schemas]->attributes[0] = (char *)malloc(sizeof(char));
	disk[no_of_schemas]->intdata = (int*)malloc(sizeof(int));
	disk[no_of_schemas]->chardata = (char**)malloc(sizeof(char*));
	while (true)
	{
		//printf("her");
		scanf("%s", name);
		if (strcmp(name, ");") == 0)break;
		else{

			scanf("%s", type);
			disk[no_of_schemas]->attributes = (char **)realloc(disk[no_of_schemas]->attributes, sizeof(char*)*(coutn_of_attr + 1));
			disk[no_of_schemas]->attributes[coutn_of_attr] = (char *)malloc(sizeof(char) * 20);
			strcpy(disk[no_of_schemas]->attributes[coutn_of_attr], name);
			if (strcmp(type, "int") == 0)
			{
				(disk[no_of_schemas]->ints)++;
				disk[no_of_schemas]->datatypes = (int*)realloc(disk[no_of_schemas]->datatypes, sizeof(int)*(coutn_of_attr + 1));
				disk[no_of_schemas]->datatypes[coutn_of_attr] = 1;
			}
			else if (strcmp(type, "string") == 0)
			{
				(disk[no_of_schemas]->chars)++;
				disk[no_of_schemas]->datatypes = (int*)realloc(disk[no_of_schemas]->datatypes, sizeof(int)*(coutn_of_attr + 1));
				disk[no_of_schemas]->datatypes[coutn_of_attr] = 2;

			}

			coutn_of_attr++;
		}
	}
	disk[no_of_schemas]->cols = coutn_of_attr;
	no_of_schemas++;
	fp = (int**)realloc(fp, sizeof(int*)*(no_of_schemas + 1));
	fp[no_of_schemas] = (int*)malloc(sizeof(int) * 2);
	fp[no_of_schemas][0] = fp[no_of_schemas][1] = 0;

}
int *common_atrribute_join_returner(int id1, int id2)
{
	int *indexes = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < disk[id1]->cols; i++)
	{
		for (int j = 0; j < disk[id2]->cols; j++)
		{
			if (strcmp(disk[id1]->attributes[i], disk[id2]->attributes[j]) == 0)
			{
				indexes[0] = i;
				indexes[1] = j;
				return indexes;
			}
		}
	}
}
/*
void join(int *p1, int *p2, int idx1,int idx2)
{
	int *mark = (int*)malloc(sizeof(int)*((p1[1]+1)));
	int *indexes = common_atrribute_join_returner(idx1, idx2);
	for (int i = 0; i < (*p1); i++){
		int flag = 0;
		for (int j = 0; j < (*p2); j++)
		{
			if (disk[idx1]->id == disk[idx2]->id)
			{
				flag = 1;
				se = (s3**)realloc(se, sizeof(s3)*(idx + 1));
				se[idx] = (s3*)malloc(sizeof(s3));
				se[idx]->id = s[i]->id;
				strcpy(se[idx]->name, s[i]->name);
				se[idx]->m1 = s[i]->m1;
				se[idx]->m2 = s[i]->m2;
				se[idx]->m3 = s[i]->m3;
				se[idx]->res = s[i]->res;
				se[idx]->avg = s[i]->avg;
				strcpy(se[idx]->hs, res[j]->hs);
				strcpy(se[idx]->town, res[j]->town);
				strcpy(se[idx]->mobile, res[j]->mobile);
				strcpy(se[idx]->picode, res[j]->picode);
				mark[j] = 1;
				idx++;
				break;
			}
		}
		if (flag == 0)
		{
			se = (s3**)realloc(se, sizeof(s3)*(idx + 1));
			se[idx] = (s3*)malloc(sizeof(s3));
			se[idx]->id = s[i]->id;
			strcpy(se[idx]->name, s[i]->name);
			se[idx]->m1 = s[i]->m1;
			se[idx]->m2 = s[i]->m2;
			se[idx]->m3 = s[i]->m3;
			se[idx]->res = s[i]->res;
			se[idx]->avg = s[i]->avg;
			strcpy(se[idx]->hs, "NA");
			strcpy(se[idx]->town, "NA");
			strcpy(se[idx]->mobile, "NA");
			strcpy(se[idx]->picode, "NA");
			idx++;
		}

	}
	for (int j = 0; j < (*p2); j++)
	{
		if (mark[j] != 1)
		{
			se = (s3**)realloc(se, sizeof(s3)*(idx + 1));
			se[idx] = (s3*)malloc(sizeof(s3));
			se[idx]->id = res[j]->id;
			strcpy(se[idx]->name, "NA");
			se[idx]->m1 = -1;
			se[idx]->m2 = -1;
			se[idx]->m3 = -1;
			se[idx]->res = -1;
			se[idx]->avg = -1;
			strcpy(se[idx]->hs, res[j]->hs);
			strcpy(se[idx]->town, res[j]->town);
			strcpy(se[idx]->mobile, res[j]->mobile);
			strcpy(se[idx]->picode, res[j]->picode);
			idx++;

		}
	}
	*p3 = idx;
}*/
void flush(int *p, char *filename, int idx)
{
	FILE *fp;
	fp = fopen(filename, "w");
	for (int strt = 0, j = 0; strt <p[0];)
	{
		for (int i = 0; i < disk[idx]->cols; i++)
		{
			if (disk[idx]->datatypes[i] == 1)
				fprintf(fp, " %d ", disk[idx]->intdata[strt++]);
			if (disk[idx]->datatypes[i] == 2)
				fprintf(fp, " %s ", disk[idx]->chardata[j++]);
		}
		fprintf(fp, "\n");
	}
}
int get_schema_index(int schema_size, char *schema)
{
	int i = 0;
	for (int i = 0; i < schema_size; i++)
	{
		if (strcmp(schema, schemanames[i]) == 0)
			return i;

	}
	return -1;
}
void print_schema(int idx, int *record_number)
{
	for (int strt = 0, j = 0; strt < record_number[0];)
	{
		for (int i = 0; i < disk[idx]->cols; i++)
		{
			if (disk[idx]->datatypes[i] == 1)
				printf("%d ", disk[idx]->intdata[strt++]);
			if (disk[idx]->datatypes[i] == 2)
				printf("%s ", disk[idx]->chardata[j++]);
		}
		printf("\n");
	}
}
int main()
{
	int **fp = (int**)malloc(sizeof(int*));
	fp[0] = (int*)malloc(sizeof(int) * 2);
	fp[0][0] = fp[0][1] = 0;
	for (int i = 0; i < 10; i++)
	{
		schemanames[i] = (char *)malloc(sizeof(char) * 20);
	}
	while (1)
	{
	
		int i = 0;
		char *str = (char*)malloc(sizeof(char) * 100);
		scanf("%s", str);
		if (strcmp(str, "exit") == 0)break;
		if (strcmp(str, "flush") == 0){
			char schema[100], file[100];
			printf("enter schema and filanmae");
			scanf("%s%s", schema, file);
			int idx = get_schema_index(no_of_schemas, schema);
			flush(fp[idx],file, idx);
		}
		if (strcmp(str, "import") == 0)
		{
			if (no_of_schemas == 0){
				printf("no such table exist ");
				break;
		            }
			char schema[100], file[100];
			printf("enter schema and filanmae");
			scanf("%s%s", schema, file);
			int idx = get_schema_index(no_of_schemas, schema);
			merge1(fp[idx], idx, file);
			print_schema(idx, fp[idx]);

		}
		if (strcmp(str, "join") == 0)
		{
			char s1[20], s2[20];

			scanf("%s %s", s1, s2);
			int idx1 = get_schema_index(no_of_schemas,s1);
			int idx2 = get_schema_index(no_of_schemas, s2);
			join(fp[idx1], fp[idx2], idx1, idx2);
		}
			int coutn_of_attr = 0;
   
		if(strcmp(str, "create") == 0){
			coutn_of_attr = 0;
			char type[10], name[10], schema[10];
			scanf("%s", schema);
			scanf("%s", schema);			
			create_schema(schema);
		}
	}
	system("pause");
	return 0;
}