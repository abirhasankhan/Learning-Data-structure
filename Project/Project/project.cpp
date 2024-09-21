#include<iostream>
using namespace std;

class node{

        public:
        int data;
        node*lchild;
        node*rchild;
        node* next;

};


class sptree{

        node*root;
    public:
        sptree(){root=NULL;}
        void insert(int data);
        node*deletes(node*root,int target);
        void preorder(node*nod);
        void inorder(node*nod);
        node*getroot(){return root;}
        void setroot(node *nod){root=nod;}
};


node*rrotation(node*root){

    node*rl=root->lchild;
    root->lchild=rl->rchild;
    rl->rchild=root;
    return rl;

}

node* lrotation(node*root){

    node*rr=root->rchild;
    root->rchild=rr->lchild;
    rr->lchild=root;
    return rr;


}
node*splay(node*root,int target){


        if(root==NULL || root->data==target){
            return root;
        }
        if(target< root->data){
            if(root->lchild==NULL){
                return root;
            }
            if(root->lchild->data>target){
                root->lchild->lchild=splay(root->lchild->lchild,target);
                root=rrotation(root);
            }
            else if(root->lchild->data<target){
                root->lchild->rchild=splay(root->lchild->rchild,target);

                if(root->lchild->rchild!=NULL){
                    root->lchild=lrotation(root->lchild);
                }
            }
            return (root->lchild == NULL)? root: rrotation(root);
        }

        else{
            if(root->rchild==NULL){
                return root;
            }
            if(root->rchild->data>target){
                root->rchild->lchild=splay(root->rchild->lchild,target);
                if(root->rchild->lchild!=NULL){
                    root->rchild=rrotation(root->rchild);
                }
            }
            else if(root->rchild->data<target){
                root->rchild->rchild=splay(root->rchild->rchild,target);
                root=lrotation(root);
            }
            return (root->rchild == NULL)? root: lrotation(root);
        }

}
void sptree::insert(int data){

        if(root==NULL){
            node*nod=new node;
            nod->data=data;
            nod->lchild=NULL;
            nod->rchild=NULL;
            nod->next=NULL;
            root=nod;
            return;
        }
        node*temp=root;
        node*temp1=NULL;

        while(temp!=NULL){

            if(data>temp->data){
                temp1=temp;
                temp=temp->rchild;
        }
        else if(data<temp->data){
                temp1=temp;
                temp=temp->lchild;
        }

        else if(data==temp->data){
            return;
        }


    }

        node*nod=new node;
        nod->data=data;
        nod->lchild=NULL;
        nod->rchild=NULL;
        nod->next=NULL;
        if(temp1->data>data){
            temp1->lchild=nod;
            root=splay(root,data);
        }
        else if(temp1->data<data){
            temp1->rchild=nod;
            root=splay(root,data);
        }



}


node*sptree::deletes(node*root,int target){

    node*temp;
    if(root==NULL){
        return NULL;
    }

    root=splay(root,target);
    if(target!=root->data){
        return root;
    }
    if(root->lchild==NULL){
        temp=root;
        root=root->rchild;
    }
    else{
        temp=root;
        root=splay(root->lchild,target);
        root->rchild=temp->rchild;
    }

    free(temp);
    return root;


}


void sptree::inorder(node*nod){
        if(nod!=NULL){

            inorder(nod->lchild);
            printf("%d\n",nod->data);
            inorder(nod->rchild);
        }

    }


void sptree::preorder(node*nod){

        if(nod!=NULL){
            printf("%d\n",nod->data);
            preorder(nod->lchild);
            preorder(nod->rchild);
        }

}

int main(){
    sptree t1;
    t1.insert(9);
    t1.insert(5);
    t1.insert(19);
    t1.insert(20);
    t1.insert(700);
    t1.insert(90);
    t1.setroot(t1.deletes(t1.getroot(),20));
    t1.preorder(t1.getroot());


}



