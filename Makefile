# Makefile for date_range program

# コンパイラ
CXX = g++

# コンパイルフラグ
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -O2

# ターゲット名
TARGET = date_range

# ソースファイル
SRC = date_range.cpp

# ビルドルール
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# クリーンアップルール
clean:
	rm -f $(TARGET)
