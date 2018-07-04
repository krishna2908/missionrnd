#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct node{
	int data;
	struct node *next;
};
int count(int * arr)
{
	int y = arr[2];
    if (arr[1] <= 2)
    	y--;
	return y / 4 - y / 100 + y / 400;
}
int diff(int  *dt1, int * dt2)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int n1 = dt1[2] * 365 + dt1[0];
	for (int i = 0; i<dt1[1] - 1; i++)n1 += month[i];
	n1 += count(dt1);
	int n2 = dt2[2] * 365 + dt2[0];
	for (int i = 0; i<dt2[1] - 1; i++)n2 += month[i];
	n2 += count(dt2);
	return (n2 - n1);
}
int between_days(struct node *date1head, struct node *date2head){
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	struct node *head1 = date1head;
	struct node *head2 = date2head;
	int *dt1 = (int*)malloc(sizeof(int) * 3);
	int *dt2 = (int*)malloc(sizeof(int) * 3);
	if (head1 == NULL || head2 == NULL)return -1;
	int c1 = 0, c2 = 0;
	//printf("%d %d\n",head1->data,head2->data);
	//date	
	c1 = head1->data, c2 = head2->data;
	head1 = head1->next, head2 = head2->next;
	//printf("%d %d\n",c1,c2);
	c1 = c1 * 10 + head1->data, c2 = c2 * 10 + head2->data;
	dt1[0] = c1, dt2[0] = c2;
	//printf("%d %d\n", c1, c2);
	if (c1>31 || c2 > 31)return 0;
	c1 = c2 = 0;
	//month
	head1 = head1->next, head2 = head2->next;
	c1 = head1->data, c2 = head2->data;
	head1 = head1->next, head2 = head2->next;
	c1 = c1 * 10 + head1->data, c2 = c2 * 10 + head2->data;
	dt1[1] = c1, dt2[1] = c2;
	//printf("%d %d\n", c1, c2);
	if (c1 > 12 || c2 > 12)return 0;
	c1 = c2 = 0;
	//year
	head1 = head1->next, head2 = head2->next;
	c1 = head1->data, c2 = head2->data;
	head1 = head1->next, head2 = head2->next;
	c1 = c1 * 10 + head1->data, c2 = c2 * 10 + head2->data;
	head1 = head1->next, head2 = head2->next;
	c1 = c1 * 10 + head1->data, c2 = c2 * 10 + head2->data;
	head1 = head1->next, head2 = head2->next;
	c1 = c1 * 10 + head1->data, c2 = c2 * 10 + head2->data;
	dt1[2] = c1, dt2[2] = c2;
	//printf("%d %d\n", c1, c2);
	int res = diff(dt1, dt2);
	if (dt1[0] == dt2[0] && dt1[1] == dt2[1] && dt1[2] == dt2[2])return 0;
	if (res < 0)res = res*(-1);
	return res - 1;
}