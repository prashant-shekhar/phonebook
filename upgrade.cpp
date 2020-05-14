#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int num;
    char addr[30];
    char mail[55];
    char name[30];
    char gender[10];
    node*left;
    node*right;
} ;
struct node * root = NULL;
struct node * root2 = NULL;
struct node * newnode(int num,char name[30],char gender[10],char addr[30], char mail[55])
{
    struct node *temp =  new node;
    temp->num = num;
    strcpy(temp->name,name);
    strcpy(temp->gender,gender);
    strcpy(temp->addr,addr);
    strcpy(temp->mail,mail);
    temp->left = temp->right = NULL;
    return temp;
};
struct node* ninsert(struct node* node, int num,char name[30], char gender[10],char addr[30], char mail[55])
{
    if(root == NULL)
    {
        root = newnode(num,name,gender,addr,mail);
    }

    if (node == NULL) return newnode(num,name,gender,addr,mail);

    if (num < node->num)
        node->left  = ninsert(node->left, num,name,gender,addr,mail);
    else if (num > node->num)
        node->right = ninsert(node->right, num,name,gender,addr,mail);


    return node;
}
struct node* nm_insert(struct node* nde, int num,char name[30], char gender[10],char addr[30], char mail[55])
{
    if(root2 == NULL)
    {
        root2 = newnode(num,name,gender,addr,mail);
    }
    /* If the tree is empty, return a new node */
    if (nde == NULL) return newnode(num,name,gender,addr,mail);

    /* Otherwise, recur down the tree */
    if (strcmp(name,nde->name)<0)
        nde->left  = nm_insert(nde->left, num,name,gender,addr,mail);
    else if (strcmp(name,nde->name)>=0)
        nde->right = nm_insert(nde->right, num,name,gender,addr,mail);

    /* return the (unchanged) node pointer */
    return nde;
}
struct node * minValue(struct node* mn_nd)
{
    struct node* current = mn_nd;
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* tr2_deleteNode(struct node* r2, char x[30], int k)
{
    if (r2 == NULL) return r2;

    if (strcmp(x,r2->name)<0)
        r2->left = tr2_deleteNode(r2->left, x , k);

    else if (strcmp(x,r2->name)>0)
        r2->right = tr2_deleteNode(r2->right, x, k);
    else
    {
       if(r2->num==k)
       {
           if (r2->left == NULL)
        {
            struct node *temp = r2->right;
            free(r2);
            return temp;
        }
        else if (r2->right == NULL)
         {
            struct node *temp = r2->left;
            free(r2);
            return temp;
        }
        struct node* temp = minValue(r2->right);
        strcpy(r2->name,temp->name);
        r2->num = temp->num;
        r2->right = tr2_deleteNode(r2->right, temp->name , temp->num);

       }
       else
       {
           r2->right = tr2_deleteNode(r2->right, x, k);
       }

    }
    return r2;
}
struct node* deleteNode(struct node* r_nd, int key)
{
    if (r_nd == NULL) return r_nd;

    if (key < r_nd->num)
        r_nd->left = deleteNode(r_nd->left, key);

    else if (key > r_nd->num)
        r_nd->right = deleteNode(r_nd->right, key);
    else
    {
        if (r_nd->left == NULL)
        {
            struct node *temp = r_nd->right;
            free(r_nd);
            return temp;
        }
        else if (r_nd->right == NULL)
         {
            struct node *temp = r_nd->left;
            free(r_nd);
            return temp;
        }
        struct node* temp = minValue(r_nd->right);
        r_nd->num = temp->num;
        r_nd->right = deleteNode(r_nd->right, temp->num);
    }
    return r_nd;
}
void inorder(struct node *r)
{

    if (r != NULL)
    {

        inorder(r->left);
        cout<<"  "<<r->name<<"   "<<r->num<<"      "<<r->gender<<"      "<<r->addr<<"      "<<r->mail<<endl;
        inorder(r->right);
    }
}
void nmsearch(struct node*fn, char nm[30])

{

    if (fn != NULL)
    {

        nmsearch(fn->left,nm);
        if(strcmp(fn->name,nm)==0)
        {cout<<"  "<<fn->name<<"      "<<fn->num<<"      "<<fn->gender<<"      "<<fn->addr<<"      "<<fn->mail<<endl;
        }
        nmsearch(fn->right,nm);
    }

}
void spsearch(struct node*sp,int num )
{
     if (sp != NULL)
    {
       if(num<sp->num)
       {
           spsearch(sp->left,num);
       }
       else if(num>sp->num)
       {
           spsearch(sp->right,num);
       }
       else
       {
           cout<<" Name - "<<sp->name<<endl;
           cout<<" Number - "<<sp->num<<endl;
           cout<<" Gender - "<<sp->gender<<endl;
           cout<<" Address - "<<sp->addr<<endl;
           cout<<" Mail - "<<sp->mail<<endl;
       }

    }
}
void gdsearch(struct node*g,char gdr[10])
{

    if (g != NULL)
    {

        gdsearch(g->left,gdr);

        if(strcmp(g->gender,gdr)==0)
         {
             cout<<"   "<<g->name<<"    "<<g->num<<"      "<<g->gender<<"     "<<g->addr<<"      "<<g->mail<<endl;
         }
        gdsearch(g->right,gdr);
    }
}

void adsearch(struct node*a,char adr[30])
{

    if (a != NULL)
    {

        adsearch(a->left,adr);

        if(strcmp(a->addr,adr)==0)
         {
             cout<<"  "<<a->name<<"   "<<a->num<<"      "<<a->gender<<"       "<<a->addr<<"       "<<a->mail<<endl;
         }
        adsearch(a->right,adr);
    }
}


void btree()
{
   struct node m;
     ifstream fin;
     fin.open("abc.txt",ios::in);

     while(!fin.eof())
     {
       fin.read((char*)&m,sizeof(m));
       if(fin.eof()) break;

      ninsert(root,m.num,m.name,m.gender,m.addr,m.mail);
      nm_insert(root2,m.num,m.name,m.gender,m.addr,m.mail);
     }
     fin.close();



}
int main()
{
    char a[10];
    int b;
    int y,x,z;
    char ch='y';
    char gd[10],nm[30],ad[30],ml[55];
    struct node n;
    btree();
    cout<<"################################################## WELCOME TO TELE DIRECTORY ##########################################"<<endl;

lbl:do
   {
    cout<<"Enter choice -"<<endl;
    cout<<"            1.Insert"<<endl;
    cout<<"            2.View"<<endl;
    cout<<"            3.Search"<<endl;
    cout<<"            4.Update"<<endl;
    cout<<"            5.Delete"<<endl;
    cout<<"            6.Exit"<<endl;
    cin>>y;
    if(y==1)
    {
     while(ch=='y')
      {
        cout<<"enter name"<<endl;
        cin>>n.name;
        cout<<"enter number"<<endl;
        cin>>n.num;
        cout<<"enter gender"<<endl;
        cin>>n.gender;
        cout<<"enter address"<<endl;
        cin>>n.addr;
        cout<<"enter mail_id"<<endl;
        cin>>n.mail;

         ofstream fout;
         fout.open("abc.txt",ios::app);
         if(!fout)
         {
          cout<<"cant open the file"<<endl;
          return 0;
         }

         fout.write((char*)&n,sizeof(n));
         ninsert(root,n.num,n.name,n.gender,n.addr,n.mail);
         nm_insert(root2,n.num,n.name,n.gender,n.addr,n.mail);
         fout.close();
        cout<<"want to enter more"<<endl;
        cin>>ch;
      }
    }
    else if(y==2)
    {
        cout<<"Want to view Contacts as - "<<endl;

        cout<<"  1. Gender wise"<<endl;
        cout<<"  2. Full list of contacts"<<endl;
        cout<<"  3. Address Wise"<<endl;
        cout<<"  4. Back to main menu"<<endl;
        cin>>x;
        if(x==1)
         {
            cout<<"enter the gender you want to search for "<<endl;
            cin>>gd;
            cout<<"   "<<"Name"<<"      "<<"Number"<<"      "<<"Gender"<<"      "<<"Address"<<"      "<<"Mail"<<endl;
            gdsearch(root,gd);
         }
        else if(x==2)
         {
            cout<<"  "<<"Name"<<"      "<<"Number"<<"      "<<"Gender"<<"      "<<"Address"<<"      "<<"Mail"<<endl;
            inorder(root);

            cout<<endl;
            inorder(root2);
         }
        else if(x==3)
        {
            cout<<"enter the address you want to search for "<<endl;
            cin>>ad;
            cout<<"  "<<"Name"<<"      "<<"Number"<<"      "<<"Gender"<<"      "<<"Address"<<"      "<<"Mail"<<endl;
            adsearch(root,ad);
        }
        else
         {
            goto lbl;
         }

    }
    else if(y==3)
    {
        int t;
        cout<<"Search details of a - "<<endl;
        cout<<"1. Specific Name"<<endl;
        cout<<"2. Specific Number"<<endl;
        cin>>t;
         if(t==1)
         {
           cout<<"Name to be searched for"<<endl;
           cin>>nm;
           cout<<"  "<<"Name"<<"      "<<"Number"<<"      "<<"Gender"<<"      "<<"Address"<<"      "<<"Mail"<<endl;
           nmsearch(root2,nm);
         }
         else if(t==2)
         {
            cout<<"enter number whose details you want to search "<<endl;
            cin>>z;
            spsearch(root,z);
         }
    }
    else if(y==4)
    {
      char nnm[30],ngdr[10],naddr[30],nmail[35];
      int nnum;
      cout<<"Enter name and number that you want to update"<<endl;
      cout<<"name : ";
      cin>>a;
      cout<<"number : ";
      cin>>b;

      spsearch(root,b);


      deleteNode(root, b);
      tr2_deleteNode(root2, a, b);

      cout<<"New name: ";
      cin>>nnm;
      cout<<"New number: ";
      cin>>nnum;
      cout<<"Gender: ";
      cin>>ngdr;
      cout<<"New Address: ";
      cin>>naddr;
      cout<<"New Mail: ";
      cin>>nmail;


      ninsert(root,nnum,nnm,ngdr,naddr,nmail);
      nm_insert(root2,nnum,nnm,ngdr,naddr,nmail);
       node r;
       ofstream fo ("temp2.txt",ios::out);
       ifstream fi ("abc.txt",ios::in);
       while(fi.read((char*)&r,sizeof(r)))
       if((r.num==b)&& strcmp(r.name,a)==0)
       {
        r.num=nnum;
        strcpy(r.name,nnm);
        strcpy(r.gender,ngdr);
        strcpy(r.addr,naddr);
        strcpy(r.mail,nmail);
        fo.write((char*)&r,sizeof(r));
       }
        else
        fo.write((char*)&r,sizeof(r));
       fi.close();
       fo.close();
       remove("abc.txt");
       rename("temp2.txt","abc.txt");


    }
    else if(y==5)
    {
      cout<<"enter name and number to be deleted"<<endl;
      cout<<"Name : ";
      cin>>a;
      cout<<"Number : ";
      cin>>b;
      deleteNode(root, b);
      tr2_deleteNode(root2, a, b);
       node rnd;
       ofstream fout ("temp.txt",ios::out);
       ifstream fin ("abc.txt",ios::in);
       while(fin.read((char*)&rnd,sizeof(rnd)))
       if(rnd.num!=b)
        fout.write((char*)&rnd,sizeof(rnd));
       fin.close();
       fout.close();
       remove("abc.txt");
       rename("temp.txt","abc.txt");

    }
    else
    {
        return 0;
    }

    cout<<"Back to main screen y/n"<<endl;
    cin>>ch;

  }while(ch=='y');

    return 0;
}

