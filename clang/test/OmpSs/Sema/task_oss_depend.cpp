// RUN: %clang_cc1 -verify -fompss-2 -ferror-limit 100 -o - -std=c++11 %s

void foo() {
}

struct S1; // expected-note {{declared here}}

class vector {
  public:
    int operator[](int index) { return 0; }
};

struct S2 {
        static int s2;
};

int S2::s2 = 3;

int main(int argc, char **argv, char *env[]) {
  vector vec;
  typedef float V __attribute__((vector_size(16)));
  V a;
  auto arr = x; // expected-error {{use of undeclared identifier 'x'}}

  argv[0 : 5] = 1; // expected-error {{OmpSs-2 array section is not allowed here}}

  #pragma oss task in // expected-error {{expected '(' after 'in'}}
  #pragma oss task in ( // expected-error {{expected expression}} expected-error {{expected ')'}} expected-note {{to match this '('}}
  #pragma oss task in () // expected-error {{expected expression}}
  #pragma oss task in (argc // expected-error {{expected ')'}} expected-note {{to match this '('}}
  #pragma oss task in (argc)) // expected-warning {{extra tokens at the end of '#pragma oss task' are ignored}}
  #pragma oss task in ( ) // expected-error {{expected expression}}
  #pragma oss task in (S1) // expected-error {{'S1' does not refer to a value}}
  #pragma oss task in(argv[1][1] = '2')
  #pragma oss task in (vec[1]) // expected-error {{expected addressable lvalue expression, array element, array shape or array section}}
  #pragma oss task in (argv[0])
  #pragma oss task in (main) // expected-error {{expected addressable lvalue expression, array element, array shape or array section}}
  #pragma oss task in (a[0]) // expected-error{{expected addressable lvalue expression, array element, array shape or array section}}
  #pragma oss task in (argv[ // expected-error {{expected expression}} expected-error {{expected ']'}} expected-error {{expected ')'}} expected-note {{to match this '['}} expected-note {{to match this '('}}
  #pragma oss task in (argv[: // expected-error {{expected expression}} expected-error {{expected ']'}} expected-error {{expected ')'}} expected-note {{to match this '['}} expected-note {{to match this '('}}
  #pragma oss task in (argv[:] // expected-error {{section length is unspecified and cannot be inferred because subscripted value is not an array}} expected-error {{expected ')'}} expected-note {{to match this '('}}
  #pragma oss task in (argv[:] // expected-error {{section length is unspecified and cannot be inferred because subscripted value is not an array}} expected-error {{expected ')'}} expected-note {{to match this '('}}
  #pragma oss task in (argv[argc: // expected-error {{expected expression}} expected-error {{expected ']'}} expected-error {{expected ')'}} expected-note {{to match this '['}} expected-note {{to match this '('}}
  #pragma oss task in (argv[argc:argc] // expected-error {{expected ')'}} expected-note {{to match this '('}}
  #pragma oss task in (argv[0:-1]) // expected-error {{section length is evaluated to a negative value -1}}
  #pragma oss task in (argv[-1:0])
  #pragma oss task in (argv[:]) // expected-error {{section length is unspecified and cannot be inferred because subscripted value is not an array}}
  #pragma oss task in (argv[3:4:1]) // expected-error {{expected ']'}} expected-note {{to match this '['}}
  #pragma oss task in(a[0:1]) // expected-error {{subscripted value is not an array or pointer}}
  #pragma oss task in(argv[argv[:2]:1]) // expected-error {{OmpSs-2 array section is not allowed here}}
  #pragma oss task in(argv[0:][:]) // expected-error {{section length is unspecified and cannot be inferred because subscripted value is not an array}}
  #pragma oss task in(env[0:][:]) // expected-error {{section length is unspecified and cannot be inferred because subscripted value is an array of unknown bound}}
  #pragma oss task in(argv[ : argc][1 : argc - 1]) // expected-error {{pointer types only allow one-level array sections}}
  #pragma oss task in(arr[0])
  #pragma oss task in(, // expected-error 2 {{expected expression}} expected-error {{expected ')'}} expected-note {{to match this '('}}
  #pragma oss task in(, : // expected-error 2 {{expected expression}} expected-error {{expected ')'}} expected-note {{to match this '('}}
  #pragma oss task in(, : ) // expected-error 2 {{expected expression}}
  foo();

  return 0;
}
