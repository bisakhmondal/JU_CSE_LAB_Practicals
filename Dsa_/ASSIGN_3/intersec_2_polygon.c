#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
typedef struct poly{
    int x,y;
    struct poly* next;
}poly;
poly* create(int x,int y){
    poly* p=(poly* )malloc(sizeof(poly));
    p->x=x;
    p->y=y;
    p->next=NULL;
    return p;
}
void add_vertex(poly**head,int x,int y){
    if(*head==NULL){
        *head=create(x,y) ;
        return;
    }
    poly* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=create(x,y);
    return;

}
void get_abc(int x1,int y1,int x2,int y2,int *a,int *b,int *c){
*a=(y2-y1);
*b=(x1-x2);
*c=(*a)*x1+(*b)*y1;
return;
}

int check_intersection(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    int A,a,B,b,C,c;
    get_abc(x1,y1,x2,y2,&A,&B,&C);
    get_abc(x3,y3,x4,y4,&a,&b,&c);
    printf("%d %d %d %d %d %d\n",A,a,B,b,C,c);
    if(a*B==A*b){
        printf("parallel lines\n");
        if(c!=C){
            return 0;
        }
        else return 1;

    }
    float int_x=(b*C-B*c)/(A*b-a*B);
    float int_y=(a*C-A*c)/(a*B-A*b);

    if(int_x>=min(x1,x2) && int_x<=max(x1,x2) &&int_x>=min(x3,x4) && int_x<=max(x3,x4) &&int_y>=min(y1,y2) && int_y<=max(y1,y2)&&int_y>=min(y3,y4) && int_y<=max(y3,y4))
    return 1;
    return 0;
}

void combination(poly*head1,poly *head2){
    poly*t1=head1;
    poly*t2=head2;
    while(head1->next!=NULL){
        poly *t11=head1;
        head1=head1->next;
        while (head2->next!=NULL)
        { poly *t12=head2;
        head2=head2->next;
        if(check_intersection(t11->x,t11->y,head1->x,head1->y,t12->x,t12->y,head2->x,head2->y)==1){
            printf("Polygon intersecting\n");
            return;}

        }
        if(check_intersection(t11->x,t11->y,head1->x,head1->y,t2->x,t2->y,head2->x,head2->y)==1){
            printf("Polygon intersecting\n");
            return;
        }
    }
        
    if(check_intersection(t1->x,t1->y,head1->x,head1->y,t2->x,t2->y,head2->x,head2->y)==1){
            printf("Polygon intersecting\n");
            return;
        }
        printf("non_intersecting_polygon\n");
}
int main(){
poly *head1=NULL,*head2=NULL;
int v1,v2;
printf("No of vertex of 1st polygon: ");
scanf("%d",&v1);
printf("No of vertex of 2nd polygon: ");
scanf("%d",&v2);
for(int i=0;i<v1;i++){
    int x,y;
    printf("enter x &y: ");
    scanf("%d%d",&x,&y);
    add_vertex(&head1,x,y);
    
}
for(int i=0;i<v2;i++){
    int x,y;
    printf("enter x &y: ");
    scanf("%d%d",&x,&y);
    add_vertex(&head2,x,y);
}
combination(head1,head2);

}