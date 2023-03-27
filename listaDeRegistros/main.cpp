#include "lista.h"
#include "Windows.h"
void expendedora();

int main()
{
expendedora();

}

void expendedora()
{
	int a,b,cuanto;
	Lista lista1;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	Sleep(500);	
	cout<<"		EXPENDEDORA				   "<<endl;
	Sleep(500);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	Sleep(700);
	do{
		system("cls");
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"		EXPENDEDORA				   "<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;		
		cout<<"1-Iniciar expendera predeterminada"<<endl
		<<"2-Iniciar expendedora con valores nuevos dados"<<endl
		<<"3-Modificar expendedora"<<endl
		<<"4-Visualizar expendedora"<<endl
		<<"5-Salir"<<endl
		<<"Opcion:";
	cin>>a;
	switch(a)
	{
		case 1:
			lista1.destruirLista();
			lista1.insertar("Coca",30,10);
			lista1.insertar("Sprite",30,10);
			lista1.insertar("Mundent",25,10);
			lista1.insertar("Fanta",20,10);
			break;
		case 2:
			lista1.destruirLista();
			do
			{
				cout<<"Cuantos productos desea agregar?";
				cin>>cuanto;
				for(int  i = 0; i < cuanto; ++i)
				{
					string prod;
					float pre;
					int cant;
					cout<<"Producto:";
					cin>>prod;
					cout<<"Precio:";
					cin>>pre;
					cout<<"Cantidad:";
					cin>>cant;
					lista1.insertar(prod,pre,cant);
				}			
				cout<<"Desea agregar mas productos?"<<endl<<"1-Si/2-NO"<<endl;
				cin>>cuanto;
				if(cuanto > 2)
				break;
			}while(cuanto == 1);
		break;
		case 3://Modificar expe
			do{
			if(lista1.vacia())
				cout<<"Expendedora vacia"<<endl;
			system("cls");
			cout<<"VISUALIZACION DE EXPENDEDORA"<<endl;
			lista1.imprimir();
			cout<<"Que es lo que desea hacer?"<<endl
				<<"1-Eliminar un producto"<<endl
				<<"2-Agregar producto"<<endl
				<<"Opcion:";
			cin>>b;
			if(b == 1)
			{
			cout<<"Digite el prodcuto que desea eliminar:";
			string p;
			cin>>p;
			lista1.eliminar(p);
			}
			if(b==2)
			{
				cout<<"Digite el producto que desea agregar";
				string p;
				float pr;
				int can;
				cin>>p;
				cout<<"Digite el precio del producto:";
				cin>>pr;
				cout<<"Digite la cantidad de producto a agregar";
				cin>>can;
			}
			cout<<"Que es lo que desea hacer?"<<endl
			<<"1-Eliminar un producto"<<endl
			<<"2-Agregar producto"<<endl
			<<"Opcion:";
			cin>>b;
			}while(b > 0 && b < 3);
			break;
		case 4:
			lista1.imprimir();
			cout<<endl;
			system("pause");
			break;
	}
}while(a> 0 && a < 5);
}
