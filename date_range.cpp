#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

// 日付を [YYYYMMDD] の形式にフォーマットする関数
std::string formatDate(const std::tm &date)
{
	std::ostringstream oss;
	oss << "[" << std::setw(4) << std::setfill('0') << (date.tm_year + 1900) << std::setw(2) << std::setfill('0')
	    << (date.tm_mon + 1) << std::setw(2) << std::setfill('0') << date.tm_mday << "]";
	return oss.str();
}

// 文字列で与えられた日付を std::tm 形式に変換する関数
std::tm parseDate(const std::string &dateStr)
{
	std::tm date = {};
	std::istringstream iss(dateStr);
	iss >> std::get_time(&date, "%Y%m%d");
	date.tm_isdst = -1; // 夏時間（DST）を自動調整
	if (iss.fail())
	{
		throw std::invalid_argument("Invalid date format. Use YYYYMMDD.");
	}
	std::mktime(&date); // 日付を正規化
	return date;
}

// 指定された日付範囲をフォーマットして出力する関数
void printDatesInRange(const std::string &startStr, const std::string &endStr)
{
	std::tm startDate;
	std::tm endDate;

	try
	{
		startDate = parseDate(startStr);
		endDate = parseDate(endStr);
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}

	if (std::difftime(std::mktime(&startDate), std::mktime(&endDate)) > 0)
	{
		std::cerr << "Error: Start date must be before or equal to end date." << std::endl;
		return;
	}

	for (std::tm date = startDate; std::difftime(std::mktime(&date), std::mktime(&endDate)) <= 0; date.tm_mday++)
	{
		std::mktime(&date); // 日付を正規化
		std::cout << formatDate(date) << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cerr << "Usage: " << argv[0] << " <start date YYYYMMDD> <end date YYYYMMDD>" << std::endl;
		return 1;
	}

	std::string startStr = argv[1];
	std::string endStr = argv[2];

	printDatesInRange(startStr, endStr);

	return 0;
}
