# Date Range Generator

このプロジェクトは、指定された日付範囲内の各日付を `[YYYYMMDD]` 形式で出力する、シンプルなC++コマンドラインプログラムです。日付範囲は、コマンドライン引数を通じてユーザーが指定します。

## 特徴

- コマンドライン引数で開始日と終了日を受け取ります。
- 指定された範囲内の各日付を `[YYYYMMDD]` 形式で出力します。
- 入力された日付の形式と範囲の妥当性を検証します。
- 不正な入力に対してエラーメッセージを表示します。

## 必要条件

- C++11以降のバージョン
- `g++`などのC++コンパイラ

## インストール

このリポジトリをローカルマシンにクローンします。

```bash
git clone https://github.com/smizuoch/Date-Range-Generator.git
cd date-range-generator
```

## プログラムのビルド

このプロジェクトには、簡単にコンパイルできるように `Makefile` が含まれています。プログラムをビルドするには、以下のコマンドを実行します。

```bash
make
```

これにより、`date_range.cpp` ソースファイルがコンパイルされ、`date_range` という名前の実行ファイルが作成されます。

## 使い方

プログラムを実行するには、以下のコマンドを使用します。

```bash
./date_range <開始日> <終了日>
```

- `<開始日>` と `<終了日>` は `YYYYMMDD` 形式で指定してください。
- プログラムは `<開始日>` から `<終了日>` までのすべての日付を、それぞれ新しい行に出力します。

### 使用例

```bash
./date_range 20240801 20240831
```

このコマンドは以下のように出力します。

```
[20240801]
[20240802]
...
[20240831]
```

## エラーハンドリング

プログラムは以下のシナリオに対して基本的なエラーハンドリングを行います。

- **無効な日付形式**: 入力された日付が `YYYYMMDD` 形式でない場合、エラーメッセージが表示されます。
- **無効な日付範囲**: 開始日が終了日より後の場合、エラーメッセージが表示されます。

## クリーンアップ

コンパイルされた実行ファイルを削除するには、以下のコマンドを実行します。

```bash
make clean
```

## ライセンス

このプロジェクトはMITライセンスの下でライセンスされています。詳細は `LICENSE` ファイルをご覧ください。