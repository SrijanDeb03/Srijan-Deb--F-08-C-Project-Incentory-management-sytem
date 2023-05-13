#include <stdio.h>
#include<math.h>

int main(){

    int choice,j,k=0;

    printf("\n-----CREATE INVENTORY-----\n");
    int add_product, product_amt[100],product_cp[100],product_sp[100],i=0,add_stock[100], remove_stock[100];
    int product_sales;
    int n;
    char product_name[100][100];
    printf("Enter the number of products you want to add : ");
    scanf("%d",&add_product);
    while(i < add_product){
        printf("Enter product name:- ");
        scanf("%s",&product_name[i]);
        printf("Enter product amount:- ");
        scanf("%d",&product_amt[i]);
        printf("Cost price of product:- ");
        scanf("%d",&product_cp[i]);
        printf("Selling price of product:- ");
        scanf("%d",&product_sp[i]);
        i++;
    }
    while(j=1){
    printf("\n----- INVENTORY MANAGEMENT SYSTEM-----\n");
    printf("1.Track product sales\n2.Stock management\n3.Generate report\n4.Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        
        printf("Enter the Product you want to track the sales of : ");
        scanf("%d", &product_sales);
        printf("Product name =  %s",product_name[product_sales-1]);
        printf("\nStock remaining=  %d",product_amt[product_sales-1]);
         
        break;
    case 2:
        
        printf("1.Add stock\n2.Remove stock\n");
        printf("Enter your choice : ");
        scanf("%d", &n);
        if(n == 1){
            int  choose_name;
            printf("Choose the Product you want to add stocks to : ");
            scanf("%d", &choose_name);
            printf("Enter the number of stocks you want to add : ");
            scanf("%d",&add_stock[choose_name-1]);
            product_amt[choose_name-1] += add_stock[choose_name-1];
        }
        else if(n == 2){
            int  choose_name1;
            printf("Choose the Product you want to remove stocks from : ");
            scanf("%d", &choose_name1);
            printf("Enter the number of stocks you want to remove : ");
            scanf("%d",&remove_stock[choose_name1-1]);
            product_amt[choose_name1-1] -= remove_stock[choose_name1-1];
        }
        else{
            printf("Wrong input\n");
        }
        break;
    case 3:
        while(k<add_product){
            printf("\nStock name = %s",product_name[k]);
            printf("\nProducts remaining= %d", product_amt[k]);
            printf("\nInitial Stocks= %d", add_stock[k]);
            printf("\nStocks sold= %d", remove_stock[k]);
            printf("\nTotal cost price= %d", add_stock[k]*product_cp[k]);
            printf("\nTotal sell price= %d", remove_stock[k]*product_sp[k]);
            if (((remove_stock[k]*product_sp[k])- (remove_stock[k]*product_cp[k]))>0){
                printf("\nProfit= %d", ((remove_stock[k]*product_sp[k])- (remove_stock[k]*product_cp[k])) );
            }
            else{
                printf("\nLoss= %d", (((remove_stock[k]*product_sp[k])- (remove_stock[k]*product_cp[k])) ));
            }
        k++;
        }
        break;
    
    
    

    case 4:
        j=0;
        break;

    
    default:

        break;
    }
    }

    return 0;
}