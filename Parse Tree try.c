#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*left;
	struct node*center;
	struct node*right;
};

struct node*insertatroot(struct node*root,char input){
	struct node*cont=(struct node*)malloc(sizeof(struct node));
	cont->data=input;
	cont->left=NULL;
	cont->center=NULL;
	cont->right=NULL;
	return cont;
}
struct node*p;
struct node*insert(struct node*root,char input){
	if(root==NULL){
		root=insertatroot(root,input);
		return root;
	}
	else{
		if((input>=97&&input<=122)){
			if(root->center==NULL){
			
			return insert(root->left,input);
		   }
		   else{
		   	return insert(root->right,input);
		   }
		}
		else if(input>=65 && input<=90){
			return insert(root->center,input);
		}
		
			
	  }
		
}
struct node*checkinsert(struct node*root,char input,char param){
	if(root->data==param){
	   if(input>=97 && input<=122){
		if(root->left==NULL){
			root->left=input;
		}
		else{
			root->right=input;
		}
	  }
	  else if(input>=65 && input<=90){
	  	root->center=input;
	  }
	}
	else checkinsert(root->center,input,param);
}
void traversal(struct node*root){
	if(root!=NULL){
		printf("%c",root->data);
		traversal(root->left);
		traversal(root->center);
		traversal(root->right);
	}
}
int main(){
	printf("Enter the no of input lines\n");
	int n_lines;
	scanf("%d",&n_lines);
	printf("Enter first line of input\n");
	char line1[10];
	gets(line1);
	printf("Enter second line of input\n");
	char line2[10];
	gets(line2);
	int count=0;
	int i;
	for(i=0;i<100;i++){
		if(line1[i]=='/'){
			break;
		}
		else if(line1[i]=='->'||line1[i]=='|'){
			continue;
		}
		count+=1;
	}
	struct node*root=NULL;
	int j;
	for(j=0;j<count;j++){
		root=insert(root,line1[j]);
	}
	int count2=0;
	int k;
	for(k=0;k<100;k++){
		if(line2=='/'){
			break;
		}
		else if(line2[k]=='->'||line2[k]=='|'){
			continue;
		}
		count2+=1;
	}
	int l;
	for(l=2;l<count2;l++){
		root=checkinsert(root,line2[l],line2[0]);
	}
	traversal(root);
	return 0;
}

