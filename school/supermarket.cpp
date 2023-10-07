#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
void cashier_menu();
void add_product();
void show_products(); 
void pay();
void warehouse_menu();
void add_product_warehouse(); 
void modify_product_warehouse(); 
void show_products_warehouse(); 
void exit_system();
// ����һ����Ʒ��
class Product 
{
    private:
        string name; // ��Ʒ����
        int quantity; // ��Ʒ����
        double price; // ��Ʒ����
    public:
        // ���캯��
        Product(string name, int quantity, double price) 
        {
            this->name = name;
            this->quantity = quantity;
            this->price = price;
        }

        // ��ȡ����
        string get_name() 
        {
            return name;
        }

        // ��ȡ����
        int get_quantity() 
        {
            return quantity;
        }

        // ��ȡ����
        double get_price() 
        {
            return price;
        }

        // ��������
        void set_quantity(int quantity) 
        {
            this->quantity = quantity;
        }

        // ���õ���
        void set_price(double price) 
        {
            this->price = price;
        }

        // ������������
        friend ostream& operator<<(ostream& out, const Product& product) 
        {
            out << product.name << "," << product.quantity << "," << product.price;
            return out;
        }
};

// ����һ��������
class Cashier 
{
    private:
        vector<Product*> products; // �������Ʒ�б�
        double total; // ������ܼ�
    public:
        // ���캯��
        Cashier() 
        {
            total = 0;
        }

        // ���һ����Ʒ�������б���
        void add_product(Product* product, int quantity) 
        {
            if (product->get_quantity() >= quantity) 
            { 
                // �������㹻
                products.push_back(product); // ��ӵ��б���
                total += product->get_price() * quantity; // �����ܼ�
                product->set_quantity(product->get_quantity() - quantity); // �۳����
                cout << "�����" << quantity << "��" << product->get_name() << "�����ﳵ������" << product->get_price() << "Ԫ��С��" << product->get_price() * quantity << "Ԫ" << endl;
            } 
            else 
            { 
                // �����治��
                cout << "��Ǹ��" << product->get_name() << "�Ŀ��ֻ��" << product->get_quantity() << "�������ܹ���" << quantity << "��" << endl;
            }
        }

        // ��ʾ�������Ʒ�б���ܼ�
        void show_products() 
        {
            cout << "���������Ʒ���£�" << endl;
            for (int i = 0; i < products.size(); i++) 
            {
                Product* product = products[i];
                cout << product->get_name() << " x " << product->get_price() / total * 100 << " = " << product->get_price() * 100 / total << "Ԫ" << endl;
            }
            cout << "�ܼƣ�" << total << "Ԫ" << endl;
        }

    // ���㲢��չ��ﳵ
    void pay() 
    {
        show_products();
        cout << "�븶��" << endl;
        products.clear();
        total = 0;
    }
};

// ����һ���ִ���
 class Warehouse 
 { 
    private: 
      string filename; //�����ļ���
      vector<Product*> products; //��Ʒ�б�
    public:  
      Warehouse(string filename) { this->filename = filename; load_data(); }// ���캯��
      // ���ļ��ж�ȡ���ݲ�������Ʒ����
    void load_data() 
    {
        ifstream in(filename.c_str()); // ���ļ�������
        if (in.is_open()) { // ����ļ��򿪳ɹ�
            string line; // ����һ���ַ������������ڴ洢ÿ������
            while (getline(in, line)) 
            { 
                // ѭ����ȡÿ������
                std::istringstream iss(line);
                std::string name, Quantity, Price;
                int quantity; // ����һ���������������ڴ洢��Ʒ����
                double price; // ����һ�����������������ڴ洢��Ʒ����
                std::getline(iss, name, ',');
                std::getline(iss, Quantity, ',');
                std::getline(iss, Price, ',');
				quantity = atoi(Quantity.c_str());
                price  = atoi(Price.c_str());            
                Product* product = new Product(name, quantity, price); // ������Ʒ����stringstream ss(line); // ��line��Ϊ������
                products.push_back(product); // ��ӵ��б���
            }
            in.close(); // �ر��ļ�������
        } 
        else 
        { 
            // ����ļ���ʧ��
            cout << "�޷����ļ�" << filename << endl;
        }
    }

    // ����Ʒ����д���ļ���
    void save_data() {
        ofstream out(filename.c_str()); // ���ļ������
        if (out.is_open()) 
        { 
            // ����ļ��򿪳ɹ�
            for (int i = 0; i < products.size(); i++) 
            { 
                // ѭ������ÿ����Ʒ����
                Product* product = products[i];
                out << *product << endl; // д��ÿ����Ʒ����Ϣ
            }
            out.close(); // �ر��ļ������
        } 
        else 
        { // ����ļ���ʧ��
            cout << "�޷����ļ�" << filename << endl;
        }
    }

    // ���һ���µ���Ʒ������������Ʒ�Ŀ��
    void add_product(string name, int quantity, double price) {
        bool found = false; // ����һ���������������ڱ���Ƿ��ҵ�ͬ����Ʒ
        for (int i = 0; i < products.size(); i++) 
        { 
            // ѭ������ÿ����Ʒ����
            Product* product = products[i];
            if (product->get_name() == name) 
            { // ����ҵ�ͬ����Ʒ
                found = true; 
                product->set_quantity(product->get_quantity() + quantity); // ���ӿ��
                cout << "������" << quantity << "��" << product->get_name() << "���ֿ⣬������" << product->get_quantity() << "��" << endl;
                break;
            }
        }
        if (!found) 
        { 
            // ���û���ҵ�ͬ����Ʒ
            Product* product = new Product(name, quantity, price); // �����µ���Ʒ����
            products.push_back(product); // ��ӵ��б���
            cout << "�����" << quantity << "��" << product->get_name() << "���ֿ⣬����" << product->get_price() << "Ԫ" << endl;
        }
    }

    // �޸�һ��������Ʒ����Ϣ
    void modify_product(string name, int quantity, double price) 
    {
        bool found = false; // ����һ���������������ڱ���Ƿ��ҵ�ͬ����Ʒ
        for (int i = 0; i < products.size(); i++) 
        { 
            // ѭ������ÿ����Ʒ����
         Product* product = products[i];
            if (product->get_name() == name) 
            { 
                // ����ҵ�ͬ����Ʒ
                found = true;
                product->set_quantity(quantity); // �޸Ŀ��
                product->set_price(price); // �޸ĵ���
                cout << "�޸���" << product->get_name() << "����Ϣ��������" << product->get_quantity() << "��������" << product->get_price() << "Ԫ" << endl;
                break;
            }
        }
        if (!found) 
        { 
            // ���û���ҵ�ͬ����Ʒ
            cout << "��Ǹ���ֿ���û��" << name << "�����Ʒ" << endl;
        }
    }

    // ��ʾ�ֿ��е�������Ʒ��Ϣ
    void show_products() {
        cout << "�ֿ��е���Ʒ���£�" << endl;
        for (int i = 0; i < products.size(); i++) 
        {
            Product* product = products[i];
            cout << product->get_name() << "��������" << product->get_quantity() << "�����ۣ�" << product->get_price() << "Ԫ" << endl;
        }
    }

    // �������Ʋ�����Ʒ��������������򷵻ؿ�ָ��
    Product* find_product(string name) 
    {
        for (int i = 0; i < products.size(); i++) {
            Product* product = products[i];
            if (product->get_name() == name) 
            {
                return product;
            }
        }
        return NULL;
    }
};

// ����һ����������
 Cashier cashier;
// ����һ�����˵�����
 void main_menu() 
 { 
    cout << "��ӭʹ�ó��й�������ϵͳ" << endl; 
    cout << "��ѡ�������" << endl; 
    cout << "1. ��������" << endl;
    cout << "2. �ִ�����" << endl;
    cout << "3. �˳�ϵͳ" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cashier_menu();
            break;
        case 2:
            warehouse_menu();
            break;
        case 3:
            exit_system();
            break;
        default:
        cout << "�����������������" << endl;
        main_menu();
        break;
}
}

// ����һ�������˵����� 
void cashier_menu() 
{ 
    cout << "������������ģʽ" << endl; 
    cout << "��ѡ�������" << endl; 
    cout << "1. �����Ʒ" << endl; 
    cout << "2. ��ʾ���ﳵ" << endl; 
    cout << "3. ���㲢����" << endl; 
    cout << "4. �������˵�" << endl; 
    int choice; 
    cin >> choice; 
    switch (choice) 
    { 
        case 1: add_product(); 
        break; 
        case 2: show_products(); 
        break; 
        case 3: pay(); 
        break; 
        case 4: main_menu(); 
        break; 
        default: cout << "�����������������" << endl; cashier_menu(); break; 
    } 
}

// ����һ�������Ʒ���� 
void add_product() 
{ 
    string name; // ����һ���ַ������������ڴ洢��Ʒ���� 
    int quantity; // ����һ���������������ڴ洢��Ʒ���� 
    cout << "��������Ʒ���ƣ�" << endl; cin >> name; // ������Ʒ����
    Warehouse warehouse("products.txt"); // �����ִ�����
    Product* product = warehouse.find_product(name); // �������Ʋ�����Ʒ���� 
    if (product != NULL) 
    { 
        // �����Ʒ���� 
        cout << "�����빺��������" << endl; 
        cin >> quantity; // ���빺������ 
        cashier.add_product(product, quantity); // ��ӵ����ﳵ�� 
    } 
    else 
    { 
        // �����Ʒ������ 
        cout << "��Ǹ���ֿ���û��" << name << "�����Ʒ" << endl;
    }
     cashier_menu(); // ���������˵�
}

    // ����һ����ʾ���ﳵ���� 
    void show_products() 
    { 
        cashier.show_products(); // ������������ķ��� 
        cashier_menu(); // ���������˵� 
    }

    // ����һ�����㲢����� 
    void pay() 
    { 
        cashier.pay(); // ������������ķ���
        Warehouse warehouse("products.txt"); // �����ִ�����
        warehouse.save_data(); // �������ݵ��ļ��� 
        cashier_menu(); // ���������˵� 
    }

   // ����һ���ִ��˵����� 
   void warehouse_menu() 
   { 
        cout << "����ִ�����ģʽ" << endl; 
        cout << "��ѡ�������" << endl; 
        cout << "1. �����Ʒ" << endl; 
        cout << "2. �޸���Ʒ" << endl; 
        cout << "3. ��ʾ�ֿ�" << endl; 
        cout << "4. �������˵�" << endl; 
        int choice; cin >> choice; 
        switch (choice) 
        { 
            case 1: add_product_warehouse(); 
            break; 
            case 2: modify_product_warehouse(); 
            break; 
            case 3: show_products_warehouse(); 
            break; case 4: main_menu(); 
            break; 
            default: cout << "�����������������" << endl; warehouse_menu(); 
            break;
        }
    }

   // ����һ�������Ʒ�������ִ�ģʽ�� 
   void add_product_warehouse() 
   { 
    string name; // ����һ���ַ������������ڴ洢��Ʒ���� 
    Warehouse warehouse("products.txt"); // �����ִ�����
    int quantity; // ����һ���������������ڴ洢��Ʒ���� 
    double price; // ����һ�����������������ڴ洢��Ʒ���� 
    cout << "��������Ʒ���ƣ�" << endl;
    cin >> name; // ������Ʒ����
    cout << "��������Ʒ������" << endl;
    cin >> quantity; // ������Ʒ����
    cout << "��������Ʒ���ۣ�" << endl;
    cin >> price; // ������Ʒ����
    warehouse.add_product(name, quantity, price); // ���òִ�����ķ���
    warehouse.save_data(); // �������ݵ��ļ���
    warehouse_menu(); // ���زִ��˵� 
    }

   // ����һ���޸���Ʒ�������ִ�ģʽ�� 
   void modify_product_warehouse() 
   { 
       string name; // ����һ���ַ������������ڴ洢��Ʒ���� 
       Warehouse warehouse("products.txt"); // �����ִ�����
       int quantity; // ����һ���������������ڴ洢��Ʒ���� 
       double price; // ����һ�����������������ڴ洢��Ʒ���� 
       cout << "��������Ʒ���ƣ�" << endl; cin >> name; // ������Ʒ���� 
       cout << "��������Ʒ������" << endl; cin >> quantity; // ������Ʒ���� 
       cout << "��������Ʒ���ۣ�" << endl; cin >> price; // ������Ʒ���� 
       warehouse.modify_product(name, quantity, price); // ���òִ�����ķ��� 
       warehouse.save_data(); // �������ݵ��ļ��� warehouse_menu(); // ���زִ��˵� 
   }

   // ����һ����ʾ�ֿ⺯�����ִ�ģʽ�� 
   void show_products_warehouse() 
   { 
       
       Warehouse warehouse("products.txt"); // �����ִ�����
       warehouse.show_products(); // ���òִ�����ķ��� 
       warehouse_menu(); // ���زִ��˵� 
   }

   // ����һ���˳�ϵͳ���� 
   void exit_system() { cout << "��лʹ�ó��й�������ϵͳ���ټ���" << endl; exit(0); }

   // �������˵����� 
   int main()
   {
         main_menu();
         return 0;
         system("pause");
    }
    