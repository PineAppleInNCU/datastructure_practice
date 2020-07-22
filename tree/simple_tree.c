#include <stdio.h>
#include <stdlib.h>
/* �ŧi tree_node �O�G���j�M�𪺸`�I */
typedef struct node{
    struct node *leftChild;
    char data;
    struct node *rightChild;
}tree_node;

typedef enum {
         true = 1 ==1 ,
         false =1 ==0
}bool;



/* �ŧi tree_pointer �O���V�`�I������ */
typedef tree_node *tree_pointer;

void create_node(tree_pointer*,tree_pointer,bool,char);
void delete_node(tree_pointer*,tree_pointer,bool);
void inorder(tree_pointer);
void preorder(tree_pointer);
void postorder(tree_pointer);

int main(){

    tree_pointer root;
    tree_pointer test_pointer;

    root=(tree_node*)malloc(sizeof(tree_node));
    root->data='a';
    //�s�y�@��data��30���`�I
    create_node(&root,root,true,'b');
    create_node(&root,root,false,'c');
    //�гy�F�G�h�������G����A�i�H�}�l���իe������ഫ
    test_pointer=root->leftChild;


    printf("%c",root->data);
    printf("%c",test_pointer->data);
    printf("\ntest inorder\n");
    inorder(root);
    printf("\ntest preorder\n");
    preorder(root);
    printf("\ntest postorder\n");
    postorder(root);

    delete_node(&root,root,true);
    if(!root->leftChild){
        printf("\ndelete success");
    }
    else{
        printf("delete fail");
    }


    return 0;
}
void create_node(tree_pointer *root,tree_pointer location,bool left_or_right,char data){
    //�ӼW�[�`�I���覡�A�u��b�Y�`�INULL���K���a��s�W�A�L�kinsert
    //left_or_right   true->left    false->right
    tree_pointer temp;
    temp=(tree_node*)malloc(sizeof(tree_node));
    temp->data=data;

    if(*root){
        if(left_or_right){
            temp->leftChild=NULL;
            temp->rightChild=NULL;
            location->leftChild=temp;
        }
        else{
            temp->leftChild=NULL;
            temp->rightChild=NULL;
            location->rightChild=temp;
        }
    }
    else{//�쥻�ګ��ШS���s�������`�I
        temp->leftChild=NULL;
        temp->rightChild=NULL;
        *root=temp;
    }
}
void delete_node(tree_pointer *root,tree_pointer location , bool left_or_right){
    //�ӧR���u���Y�Ӹ`�I���������A�@�֮����Ӹ`�I���l�`�I
    if(root){
        if(left_or_right){
            free(location->leftChild);
            location->leftChild=NULL;
        }
        else{
            free(location->rightChild);
            location->rightChild=NULL;
        }
    }
    else{
        printf("It's a empty tree!Can't delete any node.");
    }
}
void inorder(tree_pointer root){
    if(root){
        inorder(root->leftChild);
        printf("%c   ",root->data);
        inorder(root->rightChild);
    }
}
void preorder(tree_pointer root){
    if(root){
        printf("%c   ",root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}
void postorder(tree_pointer root){
    if(root){
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%c   ",root->data);
    }
}


//�ʷs�W�`�I�A�R���`�I
/* implement simple tree and five kinds of traversal>> inorder , preorder , postorder, iterative inorder , level-order  */