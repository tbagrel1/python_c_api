#include <Python.h>

static PyObject *my_module__sum_list(PyObject *self, PyObject *args) {
    PyObject *my_list = NULL;

    // Parse Python args (here, a list)
    if (!PyArg_ParseTuple(args, "O", &my_list)) {
        return NULL;
    }

    size_t list_length = PyList_Size(my_list);
    double total = 0.0;
    for (size_t i = 0; i < list_length; i++) {
        total += PyFloat_AsDouble(PyList_GetItem(my_list, i));
    }

    return PyFloat_FromDouble(total);
}

static char sum_list__docs[] =
    "sum_list(list): adds all elements in the list\n";

static char my_module__docs[] =
    "Functions:\n"
    "    sum_list(list)\n";

static PyMethodDef my_module__funcs[] = {
    {
        "sum_list", (PyCFunction) (my_module__sum_list),
        METH_VARARGS, sum_list__docs
    },
    {
        NULL, NULL, 0, NULL
    }
};

static struct PyModuleDef my_module__def = {
    PyModuleDef_HEAD_INIT,
    "my_module",
    my_module__docs,
    -1,
    my_module__funcs
};

PyMODINIT_FUNC PyInit_my_module(void) {
    return PyModule_Create(&my_module__def);
}
