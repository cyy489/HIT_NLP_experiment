本实验实现了中文分词实验的相关内容

所有的编码都统一使用GB2312
文件说明
3.1词典的构建data_to_dic.py

3.2正向最大分词匹配算法 fmm.py
反向最大分词匹配算法 bmm.py

3.3 分词效果分析assessment.py
采用的是f1值

3.4 机械搜索速度的优化 已经在fmm.py和bmm.py中体现

3.5 采取2元的分词模型 隐马尔可夫模型 并采取viterbi算法hmm.py
其中对未登录词进行了相关处理

输入输出跟报告要求一致

使用的编译器版本:
Python 3.6.8 64-bit
numpy 1.19.1

注：以上为陈啸同学内容

余羿辰同学实验内容在余羿辰NLP实验一文件夹中

编码统一使用GBK

文件说明

1.cpp、2.cpp、3.cpp都是最终产生dic.txt的系列处理程序

4.cpp、5.cpp、6.cpp分别产生seg_FMM.txt、seg_BMM.txt、score.txt

gcc version 9.2.0
