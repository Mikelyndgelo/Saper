#include<QtWidgets>
#include"counter.h"
#include"button.h"
#include "test.h"
#include<ctime>

//Написать несколько кнопок, и задать обработку каждой из них))))

int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);
    srand(time(NULL));

    Button button;
    button.show();
	
	//fuck
	//second different
	//different which don t commit
	//end test maybe
	//cherry look
	//second branchButton button;
    //button.show();
	
	//branch master	turn app.exec();
	
    return app.exec();
}


//C:/Programming/Qt projects/Saper/images.jpg


/*QLabel lbl("0");                //Надпись
QPushButton cmd("ADD");         //Нажимающая кнопка
Counter counter;                //Объект счетчик

lbl.show();
cmd.show();

//Сука всегда проверяй синтаксис ,не забывай про скобки
QObject::connect(&cmd,SIGNAL(clicked()),            //Нажатие кнопки вызывает метод slotInc класса count, который увеличтвает значение цифры
                 &counter, SLOT(slotInc())
                 );

QObject::connect(&counter,SIGNAL(counterChanged(int)),      //Этот метод (counterChanged(int)) увеличивает собственно значение цифры
                 &lbl, SLOT(setNum(int))
                 );

QObject::connect(&counter,SIGNAL(goodbay()),                //Когда значение 5 раз кликаем вызывается метод slotInc() а в нем нам передается метод goodbay()
                 &app, SLOT(quit())
                 );*/

//Слот то такая же функция по сути которая вызывается при обработке события







