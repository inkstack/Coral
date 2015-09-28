// Configuration.cpp : 定义控制台应用程序的入口点。
//

#include "boost/program_options.hpp" 

#include <iostream> 
#include <string> 
#include "stdafx.h"

namespace
{
	const size_t ERROR_IN_COMMAND_LINE = 1;
	const size_t SUCCESS = 0;
	const size_t ERROR_UNHANDLED_EXCEPTION = 2;

} // namespace 

int main(int argc, char** argv)
{
	std::cout << "Basic Command Line Parameter App" << std::endl;
	try
	{
		/** Define and parse the program options
		*/
		namespace po = boost::program_options;
		po::options_description desc("Options");
		desc.add_options()
			("help", "Print help messages")
			("add", "additional options")
			("like", "this");

		po::variables_map vm;
		try
		{
			po::store(po::parse_command_line(argc, argv, desc),
				vm); // can throw 

					 /** --help option
					 */
			if (vm.count("help"))
			{
				std::cout << "Basic Command Line Parameter App" << std::endl
					<< desc << std::endl;
				return SUCCESS;
			}

			po::notify(vm); // throws on error, so do after help in case 
							// there are any problems 
		}
		catch (po::error& e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
			std::cerr << desc << std::endl;
			return ERROR_IN_COMMAND_LINE;
		}

		// application code here // 

	}
	catch (std::exception& e)
	{
		std::cerr << "Unhandled Exception reached the top of main: "
			<< e.what() << ", application will now exit" << std::endl;
		return ERROR_UNHANDLED_EXCEPTION;

	}

	return SUCCESS;

} // main 