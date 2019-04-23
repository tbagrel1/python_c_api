# python_c_api
Example of use of Python-C API

## List of files

- `README.md`: this instruction file
- `my_module.c`: core of the module, written in *C*
- `setup__my_module.py`: *Python* script used to build the *Python* module from
    the *C* one
- `test__my_module.py`: *Python* script which represents the project where the
    external module is required

## Instructions

- Create *Python* module from the *C* one with `python3 setup__my_module.py
    install` (may need `sudo` rights on *Linux*)
- Include it in your *Python* project with `import my_module` or `from
    my_module import *`

## Author

Thomas BAGREL, Lycée Henri POINCARÉ's student, `tomsb07@gmail.com`, 2018
