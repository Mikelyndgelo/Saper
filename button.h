#ifndef BUTTON_H
#define BUTTON_H
#include<QWidget>
#include<QRegExp>
#include<QLabel>		//Look at work Git
class QPushButton;

class Button:public QWidget
{Q_OBJECT
private:
    int arr_for_frame[30]={0,1,2,3,4,5,6,7,8,16,24,32,40,48,56,57,58,59,60,61,62,63,55,47,39,31,23,15};     //Координаты клеток на границах
    int Score=0;                //Кол-во очков
    QPushButton* CheckButton;    //Указатель нажатой кнопки
    int quition_of_mines=20;    //Количество бомб
    int *arr_for_mines;        //Контейнер для хранения координат бомб
    const int size=8;       //Ширина и длина поля
    int Coordinate=0;         //Координата нажатой кнопки(int)
    QPushButton *button;
    QVector<QPushButton *> *buttons;    //Контейнер для хранения всех клавиш
    std::string path_for_image_mine="C:/Programming/Qt projects/Button/mine.jpg";
    std::string path_for_image_flag="C:/Programming/Qt projects/Button/flag.jpg";

public:
    Button(QWidget*parent=nullptr);
    void Random_Layout_of_mines();
    void GameOver();
    void Click_on_clear_field();

    ~Button();
public slots:
    void Click();
protected:
    virtual void mousePressEvent(QMouseEvent *pe);
};

#endif // BUTTON_H
