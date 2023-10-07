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
// 定义一个商品类
class Product 
{
    private:
        string name; // 商品名称
        int quantity; // 商品数量
        double price; // 商品单价
    public:
        // 构造函数
        Product(string name, int quantity, double price) 
        {
            this->name = name;
            this->quantity = quantity;
            this->price = price;
        }

        // 获取名称
        string get_name() 
        {
            return name;
        }

        // 获取数量
        int get_quantity() 
        {
            return quantity;
        }

        // 获取单价
        double get_price() 
        {
            return price;
        }

        // 设置数量
        void set_quantity(int quantity) 
        {
            this->quantity = quantity;
        }

        // 设置单价
        void set_price(double price) 
        {
            this->price = price;
        }

        // 重载输出运算符
        friend ostream& operator<<(ostream& out, const Product& product) 
        {
            out << product.name << "," << product.quantity << "," << product.price;
            return out;
        }
};

// 定义一个收银类
class Cashier 
{
    private:
        vector<Product*> products; // 购买的商品列表
        double total; // 购买的总价
    public:
        // 构造函数
        Cashier() 
        {
            total = 0;
        }

        // 添加一个商品到购买列表中
        void add_product(Product* product, int quantity) 
        {
            if (product->get_quantity() >= quantity) 
            { 
                // 如果库存足够
                products.push_back(product); // 添加到列表中
                total += product->get_price() * quantity; // 计算总价
                product->set_quantity(product->get_quantity() - quantity); // 扣除库存
                cout << "添加了" << quantity << "个" << product->get_name() << "到购物车，单价" << product->get_price() << "元，小计" << product->get_price() * quantity << "元" << endl;
            } 
            else 
            { 
                // 如果库存不足
                cout << "抱歉，" << product->get_name() << "的库存只有" << product->get_quantity() << "个，不能购买" << quantity << "个" << endl;
            }
        }

        // 显示购买的商品列表和总价
        void show_products() 
        {
            cout << "您购买的商品如下：" << endl;
            for (int i = 0; i < products.size(); i++) 
            {
                Product* product = products[i];
                cout << product->get_name() << " x " << product->get_price() / total * 100 << " = " << product->get_price() * 100 / total << "元" << endl;
            }
            cout << "总计：" << total << "元" << endl;
        }

    // 结算并清空购物车
    void pay() 
    {
        show_products();
        cout << "请付款" << endl;
        products.clear();
        total = 0;
    }
};

// 定义一个仓储类
 class Warehouse 
 { 
    private: 
      string filename; //数据文件名
      vector<Product*> products; //商品列表
    public:  
      Warehouse(string filename) { this->filename = filename; load_data(); }// 构造函数
      // 从文件中读取数据并创建商品对象
    void load_data() 
    {
        ifstream in(filename.c_str()); // 打开文件输入流
        if (in.is_open()) { // 如果文件打开成功
            string line; // 定义一个字符串变量，用于存储每行数据
            while (getline(in, line)) 
            { 
                // 循环读取每行数据
                std::istringstream iss(line);
                std::string name, Quantity, Price;
                int quantity; // 定义一个整数变量，用于存储商品数量
                double price; // 定义一个浮点数变量，用于存储商品单价
                std::getline(iss, name, ',');
                std::getline(iss, Quantity, ',');
                std::getline(iss, Price, ',');
				quantity = atoi(Quantity.c_str());
                price  = atoi(Price.c_str());            
                Product* product = new Product(name, quantity, price); // 创建商品对象stringstream ss(line); // 把line作为输入流
                products.push_back(product); // 添加到列表中
            }
            in.close(); // 关闭文件输入流
        } 
        else 
        { 
            // 如果文件打开失败
            cout << "无法打开文件" << filename << endl;
        }
    }

    // 将商品对象写入文件中
    void save_data() {
        ofstream out(filename.c_str()); // 打开文件输出流
        if (out.is_open()) 
        { 
            // 如果文件打开成功
            for (int i = 0; i < products.size(); i++) 
            { 
                // 循环遍历每个商品对象
                Product* product = products[i];
                out << *product << endl; // 写入每个商品的信息
            }
            out.close(); // 关闭文件输出流
        } 
        else 
        { // 如果文件打开失败
            cout << "无法打开文件" << filename << endl;
        }
    }

    // 添加一个新的商品或增加已有商品的库存
    void add_product(string name, int quantity, double price) {
        bool found = false; // 定义一个布尔变量，用于标记是否找到同名商品
        for (int i = 0; i < products.size(); i++) 
        { 
            // 循环遍历每个商品对象
            Product* product = products[i];
            if (product->get_name() == name) 
            { // 如果找到同名商品
                found = true; 
                product->set_quantity(product->get_quantity() + quantity); // 增加库存
                cout << "增加了" << quantity << "个" << product->get_name() << "到仓库，现在有" << product->get_quantity() << "个" << endl;
                break;
            }
        }
        if (!found) 
        { 
            // 如果没有找到同名商品
            Product* product = new Product(name, quantity, price); // 创建新的商品对象
            products.push_back(product); // 添加到列表中
            cout << "添加了" << quantity << "个" << product->get_name() << "到仓库，单价" << product->get_price() << "元" << endl;
        }
    }

    // 修改一个已有商品的信息
    void modify_product(string name, int quantity, double price) 
    {
        bool found = false; // 定义一个布尔变量，用于标记是否找到同名商品
        for (int i = 0; i < products.size(); i++) 
        { 
            // 循环遍历每个商品对象
         Product* product = products[i];
            if (product->get_name() == name) 
            { 
                // 如果找到同名商品
                found = true;
                product->set_quantity(quantity); // 修改库存
                product->set_price(price); // 修改单价
                cout << "修改了" << product->get_name() << "的信息，现在有" << product->get_quantity() << "个，单价" << product->get_price() << "元" << endl;
                break;
            }
        }
        if (!found) 
        { 
            // 如果没有找到同名商品
            cout << "抱歉，仓库中没有" << name << "这个商品" << endl;
        }
    }

    // 显示仓库中的所有商品信息
    void show_products() {
        cout << "仓库中的商品如下：" << endl;
        for (int i = 0; i < products.size(); i++) 
        {
            Product* product = products[i];
            cout << product->get_name() << "，数量：" << product->get_quantity() << "，单价：" << product->get_price() << "元" << endl;
        }
    }

    // 根据名称查找商品对象，如果不存在则返回空指针
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

// 定义一个收银对象
 Cashier cashier;
// 定义一个主菜单函数
 void main_menu() 
 { 
    cout << "欢迎使用超市管理收银系统" << endl; 
    cout << "请选择操作：" << endl; 
    cout << "1. 收银管理" << endl;
    cout << "2. 仓储管理" << endl;
    cout << "3. 退出系统" << endl;
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
        cout << "输入错误，请重新输入" << endl;
        main_menu();
        break;
}
}

// 定义一个收银菜单函数 
void cashier_menu() 
{ 
    cout << "进入收银管理模式" << endl; 
    cout << "请选择操作：" << endl; 
    cout << "1. 添加商品" << endl; 
    cout << "2. 显示购物车" << endl; 
    cout << "3. 结算并付款" << endl; 
    cout << "4. 返回主菜单" << endl; 
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
        default: cout << "输入错误，请重新输入" << endl; cashier_menu(); break; 
    } 
}

// 定义一个添加商品函数 
void add_product() 
{ 
    string name; // 定义一个字符串变量，用于存储商品名称 
    int quantity; // 定义一个整数变量，用于存储商品数量 
    cout << "请输入商品名称：" << endl; cin >> name; // 输入商品名称
    Warehouse warehouse("products.txt"); // 创建仓储对象
    Product* product = warehouse.find_product(name); // 根据名称查找商品对象 
    if (product != NULL) 
    { 
        // 如果商品存在 
        cout << "请输入购买数量：" << endl; 
        cin >> quantity; // 输入购买数量 
        cashier.add_product(product, quantity); // 添加到购物车中 
    } 
    else 
    { 
        // 如果商品不存在 
        cout << "抱歉，仓库中没有" << name << "这个商品" << endl;
    }
     cashier_menu(); // 返回收银菜单
}

    // 定义一个显示购物车函数 
    void show_products() 
    { 
        cashier.show_products(); // 调用收银对象的方法 
        cashier_menu(); // 返回收银菜单 
    }

    // 定义一个结算并付款函数 
    void pay() 
    { 
        cashier.pay(); // 调用收银对象的方法
        Warehouse warehouse("products.txt"); // 创建仓储对象
        warehouse.save_data(); // 保存数据到文件中 
        cashier_menu(); // 返回收银菜单 
    }

   // 定义一个仓储菜单函数 
   void warehouse_menu() 
   { 
        cout << "进入仓储管理模式" << endl; 
        cout << "请选择操作：" << endl; 
        cout << "1. 添加商品" << endl; 
        cout << "2. 修改商品" << endl; 
        cout << "3. 显示仓库" << endl; 
        cout << "4. 返回主菜单" << endl; 
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
            default: cout << "输入错误，请重新输入" << endl; warehouse_menu(); 
            break;
        }
    }

   // 定义一个添加商品函数（仓储模式） 
   void add_product_warehouse() 
   { 
    string name; // 定义一个字符串变量，用于存储商品名称 
    Warehouse warehouse("products.txt"); // 创建仓储对象
    int quantity; // 定义一个整数变量，用于存储商品数量 
    double price; // 定义一个浮点数变量，用于存储商品单价 
    cout << "请输入商品名称：" << endl;
    cin >> name; // 输入商品名称
    cout << "请输入商品数量：" << endl;
    cin >> quantity; // 输入商品数量
    cout << "请输入商品单价：" << endl;
    cin >> price; // 输入商品单价
    warehouse.add_product(name, quantity, price); // 调用仓储对象的方法
    warehouse.save_data(); // 保存数据到文件中
    warehouse_menu(); // 返回仓储菜单 
    }

   // 定义一个修改商品函数（仓储模式） 
   void modify_product_warehouse() 
   { 
       string name; // 定义一个字符串变量，用于存储商品名称 
       Warehouse warehouse("products.txt"); // 创建仓储对象
       int quantity; // 定义一个整数变量，用于存储商品数量 
       double price; // 定义一个浮点数变量，用于存储商品单价 
       cout << "请输入商品名称：" << endl; cin >> name; // 输入商品名称 
       cout << "请输入商品数量：" << endl; cin >> quantity; // 输入商品数量 
       cout << "请输入商品单价：" << endl; cin >> price; // 输入商品单价 
       warehouse.modify_product(name, quantity, price); // 调用仓储对象的方法 
       warehouse.save_data(); // 保存数据到文件中 warehouse_menu(); // 返回仓储菜单 
   }

   // 定义一个显示仓库函数（仓储模式） 
   void show_products_warehouse() 
   { 
       
       Warehouse warehouse("products.txt"); // 创建仓储对象
       warehouse.show_products(); // 调用仓储对象的方法 
       warehouse_menu(); // 返回仓储菜单 
   }

   // 定义一个退出系统函数 
   void exit_system() { cout << "感谢使用超市管理收银系统，再见！" << endl; exit(0); }

   // 调用主菜单函数 
   int main()
   {
         main_menu();
         return 0;
         system("pause");
    }
    