
# 南开大学2023高级语言程序设计2-2大作业
## 基于C++语言的Qt应用《RemoteMoon》
        
        

## 作者
Weihua Kwong

## 说明
1.  Finished分支 是最终版本的源文件，请下载该分支内文件
2.  master分支 是开发工程分步提交的文件，旨在展现开发过程

## 程序名称
RemoteMoon

## 开发软件

Qt 5.12.2 MinGW 64-bit

Qt Creator 10.0.0 (community)

## 设计构想

*月为真切发生在眼前的光与色彩涂抹黑色，可总高悬、遥远*

本程序尝试以图形化方式展现与月亮相关的色彩与光影变化：

​	以目标主导，据个性化想法进行设计，

​	按需学习新函数与算法，有创新结构，

​	异于游戏和工具类程序以方法为主导的开发。

​	界面优美细节精致体验感强，

​	缺点是复杂度与可玩性较低。

## 程序内容

##### 1. 开始界面-interface

- Start 开始游戏

- Help 开发帮助

- Exit   退出程序

##### 2. 晴暮海月-ocean

*海中月影，触碰假影无果*

互动玩法1 ：Press "Space" to catch the moon in ocean

云朵位置随按击更新，碰撞判断

##### 3-0.过渡窗口-dialog	

##### 3. 夜至光散-lightray

*斑斓淡散，仅剩月光耀眼*

动画效果，各色光线逐渐散去

##### 4. 日月去来-moon

*日间等月，夜来有月良机*

隐藏切换窗口按钮，背景转换时再显示

##### 5-0. 过渡窗口-dialog2

##### 5. 嫦娥导航-play

*算法助力，至月宫不迷路*

互动玩法2 ：Clarify the moon

随机位置颜色生成九个假月亮，点击判断删除假月

##### 6. 静享静夜-finalplot

*今夜再见，静夜再见静月*

更新位置至完全升起

## 程序亮点

##### 1. ocean-云朵位置随按击更新，碰撞判断：

keyPressEvent关联Space键，检测按击并更新

碰撞通过图形相对位置大小判断

    //位置更新
    void Ocean::keyPressEvent(QKeyEvent *event)
    {
        if (event->key() == Qt::Key_Space)
        {
            cloudX += 10 + QRandomGenerator::global()->bounded(-25, 25);
            cloudY += 10 + QRandomGenerator::global()->bounded(-50, 50);
            cloudX2 -= -20 + QRandomGenerator::global()->bounded(-30, 30);
            cloudY2 += 10 + QRandomGenerator::global()->bounded(-45, 45);
        }
        //越出边界更新回初始位置
        ···
    //碰撞检测
    	int dx = moonX - cloudX,dx2 = moonX - cloudX2;
    	int dy = moonY - cloudY,dy2 = moonY - cloudY2;
    	int dist = qSqrt(dx*dx + dy*dy),dist2 = qSqrt(dx2*dx2 + dy2*dy2);
    	if (dist < 100 ||dist2 < 100)
    	{
    	    close();
    	    class dialog* dialog=new class dialog();
    	    dialog->show();
    	}
    }
不足：碰撞不够立体，可以通过检测实时位置改进

##### 2. lightray-动画效果，各色光线逐渐散去:

生成七束光线，不同角度与移动方向淡出屏幕，定时弹出按钮

    // 创建图形场景
    QGraphicsScene* scene = new QGraphicsScene(this); 
    QGraphicsView* view = new QGraphicsView(scene, this);
    view->setAttribute(Qt::WA_DeleteOnClose);
    
    ////light1
    QGraphicsLineItem* lightRay1 = new QGraphicsLineItem(0, 0, width(), height());
    lightRay1->setPen(QPen(Qt::yellow, 24));
    scene->addItem(lightRay1);
    ···
    
    qreal angle = qDegreesToRadians((double)-45);
    qreal dx = 4 * qCos(angle);
    qreal dy = -3 * qSin(angle);
    QTimer* timerLight = new QTimer(this);
    connect(timerLight, &QTimer::timeout, [=]
    {
    	QPointF pos = lightRay1->pos();
    	lightRay1->setPos(pos - QPointF(dx, dy));
    	···
    });
    timerLight->start(50); // 每50毫秒更新一次光线位置

不足：没有实现光线的更新重复

##### 3. moon-隐藏切换窗口按钮，背景转换时再显示:

月的圆缺变化通过叠加图层绘制而成，定时切换背景与显示

    void moon::paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing,true);
        ···
    
        // 绘制圆形月亮
        painter.setBrush(Qt::yellow);
        painter.drawEllipse(width0-width,radius,radius,radius);
        painter.setPen(Qt::NoPen);
    
        // 根据月相调整绘制方式
        if (m_phase > 0 && m_phase < 0.5)
            {
                int arc = m_phase * 720;
                painter.setBrush(QColor(192,192,192));
                painter.drawPie(width0-width, radius, radius, radius, 90 * 16 - arc / 2, arc * 16);//
    
                button->hide();
            }
        else
            {
                int arc = (1.0 - m_phase) * 720;
                painter.setBrush(Qt::black);
                painter.drawPie(width0-width, radius, radius, radius, 90 * 16 - arc / 2, arc * 16);//
    
                // 绘制月亮的阴影效果
                QPainterPath path;
                path.addEllipse(width0-width, radius, radius, radius);//
                path.addRect(rect());
                painter.setClipPath(path);
    
                QLinearGradient gradient(QPointF(0, 0), QPointF(0, 400));
                gradient.setColorAt(0, QColor(0, 0, 0, 255));
    
                painter.setBrush(gradient);
                painter.drawRect(rect());
    
                button->show();
            }
    }
    
    void moon::timerEvent(QTimerEvent *)
    {
        m_phase += 0.01;
        if (m_phase >= 1.0)
        {
            m_phase = 0.0;
        }
        update();
    }
不足：月不生动，可用贴图月相变化绘制

##### 4. play-随机位置颜色生成九个假月亮，点击判断删除假月:

月的颜色和位置全随机，click事件判断删除

    void Play::createMoons()
    {
        animationGroup = new QSequentialAnimationGroup();
        for (int i = 0; i < moonCount; ++i) 
        {
            QColor color = QColor::fromRgb(QRandomGenerator::global()->bounded(256),
                                           QRandomGenerator::global()->bounded(256),
                                           QRandomGenerator::global()->bounded(256));
            QPoint pos = QPoint(QRandomGenerator::global()->bounded(width() - moonSize),
                                QRandomGenerator::global()->bounded(height() - moonSize));
            moons[i] = new QLabel(this);
            moons[i]->setFixedSize(moonSize, moonSize);
            moons[i]->move(pos);
            moons[i]->setBackgroundRole(QPalette::Base);
            moons[i]->setAutoFillBackground(true);
            moons[i]->setStyleSheet(QString("background-color: %1; border-radius: 				%2px;").arg(color.name()).arg(moonSize / 2));
            QPropertyAnimation *animation = new QPropertyAnimation(moons[i], "geometry");
            animation->setDuration(1000);
            animation->setStartValue(QRect(pos, QSize(moonSize, moonSize)));
            animation->setEndValue(QRect(pos, QSize(0, 0)));
            animationGroup->addAnimation(animation);
        }
    }
    
    void Play::mousePressEvent(QMouseEvent *event)
    {
        for (int i = 0; i < moonCount; ++i)
        {
            if (moons[i] != nullptr && moons[i]->geometry().contains(event->pos()))
            {
                delete moons[i];
                moons[i] = nullptr;
                count--;
                break;
            }
        }
        // 如果所有图案都已删除，启用button
        if (count == 0)
        {
            button->show();
            button->setEnabled(true);
        }
    }
不足：缺少动态移动，不够生动

## 开发困难

1. 定时器转换窗口，同时跳出多个窗体
2. 背景音乐的切换，Ending时播放收尾

## 总结思考

1. 类名和函数名的重复：命名时大小写，到程序内会默认小写

2. 头文件引用：重复引用，无效引用 Eg：<QWidgets> including  <QPainterLineItem>

3. 指针初始化的规划：简单情况在头文件初始化更条理，复杂情况在函数中方便定位

4. 寻找高效调试优化方法：一次一次运行调整太过复杂

5. 思考：

   - 目标为导向的设计代码逻辑要清晰，需有设计规划
- 程序复杂度和细节优化需要并重
   - Qt自身特点是qmake使用，更强调高效的学习与及时使用
   - 同一思路可以多尝试不同的设计思路，这也是程序设计黑猫白猫的特点所在

## 感谢浏览
开发谬误，恳请指正

邮箱：w00waykwong@gmail.com
   
祝好！
