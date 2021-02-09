#ifndef _CAR_H_
#define _CAR_H_

// 自動車クラス
class CCar
{
  public:
    // コンストラクタ
    CCar();
    // デストラクタ
    ~CCar();
    // 移動メソッド
    void move();
    // 燃料補給メソッド
    void supply(int fuel);
  private:
    int m_fuel;
    int m_migration;
};

#endif
