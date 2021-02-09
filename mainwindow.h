#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::MainWindow *ui;
    //两个算法共有
    double ranCityPosition[55][2];
    //遗传算法
    int maxgen=200;// 最大进化代数
    int sizepop=100; // 种群数目
    double pcross=0.6; // 交叉概率
    double pmutation=0.1; // 变异概率
    int lenchrom=30;
    double city_pos[55][2];
    int chrom[100][55]; // 种群
    int best_result[55]; // 最佳路线
    double min_distance; // 最短路径长度

    void init(void); // 种群初始化函数
    double distance(double *,double *); // 计算两个城市之间的距离
    double * min(double *); // 计算距离数组的最小值
    double path_len(int *); // 计算某一个方案的路径长度，适应度函数为路线长度的倒数
    void Choice(int [100][55]); // 选择操作
    void Cross(int [100][55]); // 交叉操作
    void Mutation(int [100][55]); // 变异操作
    void Reverse(int [100][55]); //逆转操作
    void GA();
};
#endif // MAINWINDOW_H
