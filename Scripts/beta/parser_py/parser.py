# imports

import sys
import os
import json
import platform
import _thread
import threading
from http.server import BaseHTTPRequestHandler, HTTPServer

parsed_problems = 0


class ProblemParser(BaseHTTPRequestHandler):
  def _set_response(self):
    self.send_response(200)
    self.send_header('Content-type', 'text/html')
    self.end_headers()
    
  def do_POST(self):
    global parsed_problems
    # global problem_count
    parsed_problems += 1
    content_length = int(self.headers['Content-Length'])
    body = self.rfile.read(content_length)
    problem_data = json.loads(body.decode('utf8'))
    # print(problem_data)
    
    # make the test files
    problem_url = problem_data['url']
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
    filename = problem_code+ ".cpp" + ":tests"
    if platform.system() == "Windows":
      filename = problem_code + ".cpp" + "__tests"
    print(filename)
    current_path = os.path.join(os.getcwd(), problem_code)
    os.mkdir(current_path)
    filename = os.path.join(current_path, filename)
    with open(filename, "w") as f:
      f.write(json.dumps(total_tests))
    print("Problem code: ", problem_code)
    print("Parsed Problems: ", parsed_problems)
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
    print("Hello")
    httpd.serve_forever()
    
  except KeyboardInterrupt:
    pass
  httpd.server_close()
  print("Server Closed")
  


if __name__ == "__main__":
  args_count = len(sys.argv)
  problem_count = 1
  if args_count > 1:
    problem_count = int(sys.argv[1])
  print(sys.argv, args_count, problem_count)
  competitive_companion_server()