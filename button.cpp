#include "button.h"
#include<QPushButton>
#include<QVector>
#include<QGridLayout>
#include<QLabel>
#include<QHBoxLayout>
#include<QMouseEvent>

Button::Button(QWidget *parent):QWidget(parent)
{
    buttons = new QVector<QPushButton *>();
    Random_Layout_of_mines();
    QGridLayout *layout = new QGridLayout;
    setLayout(layout);

    for(int i = 0; i < size; i++)      //Создание нашего поля
    {
        for(int j=0;j<size;++j)
        {
            button = new QPushButton;
            button->setFixedSize(30,30);
            layout->addWidget(button,i,j);
            buttons->append(button);
        }
    }
    //Обработка нажатия клавиши
    for(int i = 0; i < size*size; i++)
    {
		int a = 5;//	//проверка коммита
        connect(buttons->at(i),SIGNAL(clicked()),SLOT(Click()));
    }
}

void Button::Click()
{
   CheckButton= ((QPushButton*)sender());
   int current=0;
   bool clear_field;        //Когда нажимаем на поле с бомбой, параллейно рисуется еще и кол-во бомб вокруг (нужно убрать в этом случае доступ к функции Click_on_clear_field()
   for(int i = 0; i < size*size; i++)
   {
       clear_field=true;
       if(buttons->at(i)==CheckButton)
       {
            Coordinate=current;
            for(int j=0;j<quition_of_mines;++j)
            {
                if(arr_for_mines[j]==Coordinate)
                {
                    GameOver();
                    clear_field=false;
                }
            }
            if(clear_field)
                Click_on_clear_field();
       }
       current++;
   }
}

//Конец игры
void Button::GameOver()
{
    QPixmap pix(path_for_image_mine.c_str());
    for(int i=0,j=0;j<quition_of_mines;++i)
    {
        if(arr_for_mines[j]==i)
        {
            buttons->at(i)->setIcon(pix);
            ++j;
            i=0;
        }
    }
    //Вывод на экран о конце игры и количестве полученных очков
    QString sc=QString::number(Score);
    QLabel *label=new QLabel;
    label->setText("Game Over\n  Score:"+sc);
    label->setStyleSheet(QString("font-size: %1px").arg(20));       //ИЗМЕНЕНИЕ РАЗМЕРА QLabel
    label->setGeometry(700,390,90,65);
    label->show();
}

//Нажатие на чистое поле
void Button::Click_on_clear_field()
{
    int Temp_Coordinate=Coordinate;         //Временная коорданита кнопки
    Score+=10;                              //Увеличение очков
    int current_of_munes_above=0;           //Счетчик мин вокруг
    bool Frame=false;                       //Проверка на то нажали ли мы кнопку на границе поля

    for(int i=0;i<30;++i)       //Проверка на нажатие кнопки у края поля(подсчет мин вокруг будет по другому будет по другому)
    {
        if(Coordinate==arr_for_frame[i])
        {
            CheckButton->setText(QString::number(current_of_munes_above));
            Frame=true;
            break;
        }
    }
    if(!Frame)  //Подсчет кол-ва бомб вокруг клетки, если мы находимся не на границе поля
    {
        for(int i=0;i<quition_of_mines;++i)    //Нужно проверить 8 полей вокруг
        {
            Temp_Coordinate=Coordinate;
            if(arr_for_mines[i]==--Temp_Coordinate)
                current_of_munes_above++;
            Temp_Coordinate=Coordinate;
            if(arr_for_mines[i]==++Temp_Coordinate)
                current_of_munes_above++;
            Temp_Coordinate=Coordinate;
            if(arr_for_mines[i]==(Temp_Coordinate+=8))
                current_of_munes_above++;
            Temp_Coordinate=Coordinate;
            if(arr_for_mines[i]==(Temp_Coordinate+=7))
                current_of_munes_above++;
            Temp_Coordinate=Coordinate;
            if(arr_for_mines[i]==(Temp_Coordinate+=9))
                current_of_munes_above++;
            Temp_Coordinate=Coordinate;
            if(arr_for_mines[i]==(Temp_Coordinate-=8))
                current_of_munes_above++;
            Temp_Coordinate=Coordinate;
            if(arr_for_mines[i]==(Temp_Coordinate-=7))
                current_of_munes_above++;
            Temp_Coordinate=Coordinate;
            if(arr_for_mines[i]==(Temp_Coordinate-=9))
                current_of_munes_above++;
        }
    }

    if(Frame)
    {
        if(Coordinate==0)       //Ебаное спагетти
        {
            for(int i=0;i<quition_of_mines;++i)
            {
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==++Temp_Coordinate)
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=8))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=9))
                    current_of_munes_above++;;
            }
        }
        if(Coordinate==63)       //Ебаное спагетти
        {
            for(int i=0;i<quition_of_mines;++i)
            {
                if(arr_for_mines[i]==--Temp_Coordinate)
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=8))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=9))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
            }
        }
        if(Coordinate==7)       //Ебаное спагетти
        {
            for(int i=0;i<quition_of_mines;++i)
            {
                if(arr_for_mines[i]==--Temp_Coordinate)
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=8))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=7))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
            }
        }
        if(Coordinate==56)       //Ебаное спагетти
        {
            for(int i=0;i<quition_of_mines;++i)
            {
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=8))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=7))
                    current_of_munes_above++;
                if(arr_for_mines[i]==++Temp_Coordinate)
                    current_of_munes_above++;
            }
        }
        if(Coordinate>0&&Coordinate<7)                  //Верхняя граница
        {
            for(int i=0;i<quition_of_mines;++i)    //Нужно проверить 8 полей вокруг
            {
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==--Temp_Coordinate)
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==++Temp_Coordinate)
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=8))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=7))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=9))
                    current_of_munes_above++;
            }
        }

        if(Coordinate>56&&Coordinate<63)                  //Нижняя граница
        {
            for(int i=0;i<quition_of_mines;++i)    //Нужно проверить 8 полей вокруг
            {
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==--Temp_Coordinate)
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==++Temp_Coordinate)
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=8))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=7))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=9))
                    current_of_munes_above++;
            }
        }

        if(Coordinate==8||Coordinate==16||Coordinate==24||Coordinate==32||Coordinate==40||Coordinate==48)                  //Левая граница
        {
            for(int i=0;i<quition_of_mines;++i)
            {
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==++Temp_Coordinate)
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=8))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=9))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=8))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=7))
                    current_of_munes_above++;
            }
        }

        if(Coordinate==15||Coordinate==23||Coordinate==31||Coordinate==39||Coordinate==47||Coordinate==55)                   //Правая граница
        {
            for(int i=0;i<quition_of_mines;++i)
            {
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==--Temp_Coordinate)
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=8))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate+=7))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=8))
                    current_of_munes_above++;
                Temp_Coordinate=Coordinate;
                if(arr_for_mines[i]==(Temp_Coordinate-=9))
                    current_of_munes_above++;
            }
        }
    }
    CheckButton->setText(QString::number(current_of_munes_above));
}

//Задаем рандомное расположение бомб на карте (БЕЗ ПОВТОРЕНИЙ)
void Button::Random_Layout_of_mines()
{
    arr_for_mines=new int[quition_of_mines];
    bool ok;
    for (int i = 1;i < quition_of_mines;)           //Не забудь про эту мину
    {
       ok = true;
       int element = rand() % (size*size);
       for (int j = 0; j < i; j++)
       {
           if (arr_for_mines[j] == element)
               ok = false;
       }
       if (ok)
       {
           arr_for_mines[i] = element;
           ++i;
       }
     }
    arr_for_mines[0]=1;
}

Button::~Button()
{
    delete [] arr_for_mines;
}

//Нет инициализации нажатой кнопки и программа вылетает...
void Button::mousePressEvent(QMouseEvent *pe)           //Ставим флажок если нажата правая кнопка мыши
{
    CheckButton = ((QPushButton*)sender());
    QPixmap flag(path_for_image_flag.c_str());
    if(pe->button()&Qt::RightButton)
        CheckButton->setIcon(flag);
}



















