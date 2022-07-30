#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class shopping{
private:
    int pcode;
    float price;
    float disc;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remv();
    void lst();
    void receipt();

};

void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t________________________________\n";
    cout<<"\t\t\t                                \n";
    cout<<"\t\t\t      Supermarket Main MEnu     \n";
    cout<<"\t\t\t                                \n";
    cout<<"\t\t\t________________________________\n";
    cout<<"\t\t\t                                \n";

    cout<<"\t\t\t|  1) Administrator    |\n";
    cout<<"\t\t\t|                      |\n";
    cout<<"\t\t\t|  2) Buyer            |\n";
    cout<<"\t\t\t|                      |\n";
    cout<<"\t\t\t|  3)  Exit            |\n";
    cout<<"\t\t\t|                      |\n";
    cout<<"\n\t\t\t Please select!";
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t\t Enter Email  \n";
            cin>>email;
            cout<<"\t\t\t Enter password";
            cin>>password;

            // for only admin can enter the password
            if(email=="mdjauhariqubal469@gmail.com" && password == "iqbal@1234"){
                administrator();
            }
            else{
                cout<<"Invalid email/Password";

            }
            break;
        case 2:
            {
                buyer();
            }
        case 3:
            {
                exit(0);
            }
            break;
        default:
            {

                cout<<"Please select from the given options";
            }
            break;
    }
    goto m;

}

// this is for administrator can add, modify and delete the items
void shopping:: administrator(){
    n:
    int choice;
    cout<<" \n\n\n\t\t\t Administrator menu";
    cout<<" \n\t\t\t|______1) Add the product______ |";
    cout<<" \n\t\t\t|______2) Modify the product___ |";
    cout<<" \n\t\t\t|______3) Delete the product___ |";
    cout<<" \n\t\t\t|______4) Back to main menu____ |";

    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;

    switch(choice){
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        remv();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"Invalid choice!";
    }
    goto n;

}

// This function is for customer
void shopping :: buyer(){
    o:
    int choice;
    cout<<"\t\t\t  Buyer \n";
    cout<<"\t\t\t________________ \n";
    cout<<"\t\t\t                 \n";
    cout<<"\t\t\t 1) Buy  product \n";
    cout<<"\t\t\t                 \n";
    cout<<"\t\t\t 2) Go back      \n";
    cout<<"\t\t\t Enter your choice :";
    cin>>choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"Invalid choice!";
            break;

    }
    goto o;
}

// Add new product. only administrator can add product and the items detail store in file, here i use file handling
void shopping :: add(){
    m:
    fstream data;
    int c;
    int token =0;
    float p;
    float d;
    string n;

    cout<<"\n\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t price of the product ";
    cin>>price;
    cout<<"\n\n\t Discount on the product ";
    cin>>disc;

    data.open("database.txt", ios::in);

    if(!data){
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<endl;
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token == 1)
        goto m;
    else{
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<endl;
        data.close();
    }
    cout<<"\n\n\t\t Record inserted !";
}


void shopping :: edit(){
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t  Modify the record";
    cout<<"\n\t\t\t product code";

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n File doesn't exist";
    }
    else{
        data1.open("database.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>disc;
        while(!data.eof()){
           if(pkey==pcode){
            cout<<"\n\t\t Product new code :";
            cin>>c;
            cout<<"\n\t\t Nme of the product :";
            cin>>n;
            cout<<"\n\t\t Price";
            cin>>p;
            cout<<"\n\t\t Discount :";
            cin>>d;
            data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
            cout<<"\n\n\t\t Record edited ";
            token++;


           }
           else{
            data1<<" " <<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";

           }
           data>>pcode>>pname>>price>>disc;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry";

        }
    }
}

void shopping :: remv(){

    fstream data, data1;
    int pkey;
    int token = 0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data){
        cout<<"File doesn't exist";
    }
    else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>disc;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else{
               data1<<" " <<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
            }
            data>>pcode>>pname>>price>>disc;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

         if(token==0){
            cout<<"\n\n Record not found. ";

        }
    }
}

void shopping :: lst(){
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n|_____________________________________________________\n";
    cout<<"ProNo"<<"\t\t"<<"Name"<<"\t\t"<<"Price"<<"\n";
    cout<<"\n\n|_____________________________________________________\n";
    data>>pcode>>pname>>price>>disc;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<disc<<endl;
        data>>pcode>>pname>>price>>disc;


    }
    data.close();

}


void shopping :: receipt(){

     fstream data;

     int arrc[100];    // array of pcode
     int arrq[100];    // array of quantity
     char choice;
     int d=0;
     float amount=0;
     float disc=0;
     float total=0;

     cout<<"\n\n\t\t\t  RECEIPT";
     data.open("database.txt", ios::in);
     if(!data){
        cout<<"\n\n Empty database";

     }
     else{
        data.close();

        lst();
        cout<<"\n___________________________________________\n";
        cout<<"\n|                                          \n";
        cout<<"\n|     Please place the order               \n";
        cout<<"\n|                                          \n";
        cout<<"\n___________________________________________\n";

        do{
            m:
            cout<<"\n\n Enter Product code :";
            cin>>arrc[d];
            cout<<"\n\n Enter the quantity :";
            cin>>arrq[d];
            for(int i = 0; i<d;i++){
                if(arrc[d]==arrc[i]){
                    cout<<"\n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }
            d++;
            cout<<"\n\n Do you buy another product?  if yes then press y else no";
            cin>>choice;
        }
        while(choice == 'y');

        cout<<"\n\n\\t\t\t___________RECEIPT____________________\n";
        cout<<"\n ProductNo \t Product name \t Product quantity \t Price \t Amount \t Amount with discount \n";

        for(int i =0; i<d;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>disc;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount = price*arrq[i];
                    disc = amount - (amount*disc/100);
                    total = total+disc;
                    cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<disc;
                }
                data>>pcode>>pname>>price>>disc;
            }

     }
     data.close();
     }
     cout<<"\n\n_____________________________________________";
     cout<<"\n Total amount : "<<total;
}


int main(){
   shopping s;
   s.menu();

}

