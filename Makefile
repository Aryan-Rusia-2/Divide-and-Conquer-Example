run:
	chmod u+x soln/.build/build.sh
	bash setup.sh
	python3 TestCenter-master/testcenter.py -s soln -t test-cases -e --timeout 2
all:
	chmod u+x soln/.build/build.sh
	bash setup.sh
	python3 TestCenter-master/testcenter.py -s soln -t test-cases --timeout 2
verbose:
	chmod u+x soln/.build/build.sh
	bash setup.sh
	python3 TestCenter-master/testcenter.py -s soln -t test-cases -e -v --timeout 2
all-verbose:
	chmod u+x soln/.build/build.sh
	bash setup.sh
	python3 TestCenter-master/testcenter.py -s soln -t test-cases -v --timeout 2
validate:
	python3 submission_validator.py