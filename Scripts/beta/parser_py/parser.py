# imports

import sys
import os
import json
import platform
import _thread
import threading
from shutil import copy
from colorama import init 
from termcolor import colored 
from http.server import BaseHTTPRequestHandler, HTTPServer

parsed_problems = 0
template_path = 'D:\\Competitive\\GetGood\\templates\\ankur\\starter.cpp'

class ProblemParser(BaseHTTPRequestHandler):
    def _set_response(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
    
    def do_POST(self):
        global parsed_problems
        global template_path
    
        parsed_problems += 1
        content_length = int(self.headers['Content-Length'])
        body = self.rfile.read(content_length)
        problem_data = json.loads(body.decode('utf8'))
    
        # make the test files
        problem_url = problem_data['url']
        print()
        print(problem_url)
        problem_code = problem_url.split('/')[-1]
        problem_tests = problem_data['tests']
        total_tests = []
        for test in problem_tests:
            single_test = {
                "test": test["input"],
                "correct_answers": [test["output"].strip()]
            }
            total_tests.append(single_test)
        test_filename = problem_code + ".cpp" + ":tests"
        if platform.system() == "Windows":
            test_filename = problem_code + ".cpp" + "__tests"
        current_path = os.path.join(os.getcwd(), problem_code)
        os.mkdir(current_path)
        test_filename = os.path.join(current_path, test_filename)
        with open(test_filename, "w") as f:
            f.write(json.dumps(total_tests))
    
        # copy the starter code
        code_filename = problem_code + '.cpp'
        copy(template_path, os.path.join(current_path, code_filename))
        print("Problem code: ", problem_code)
        for test in total_tests:
            print(test)
        print(colored("Parsed Problems: "+ str(parsed_problems)+'/'+ str(problem_count), 'green'))
        self._set_response()
        if parsed_problems == problem_count:
            threading.Thread(target=self.server.shutdown, daemon=True).start()

def competitive_companion_server():
    host = 'localhost'
    port = 12345
    server_address = (host, port)
    handler_class = ProblemParser
    httpd = HTTPServer(server_address, handler_class)
    try:
        print("Starting parsing problems...")
        httpd.serve_forever()
    
    except KeyboardInterrupt:
        pass
    httpd.server_close()
    print()
    print(colored(str(problem_count)+ " problems parsed. Good Luck !", 'green'))
  


if __name__ == "__main__":
    init()
    args_count = len(sys.argv)
    problem_count = 1
    if args_count > 1:
        problem_count = int(sys.argv[1])
    competitive_companion_server()