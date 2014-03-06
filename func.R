# This function is invoked by the C program r_test

add1 <- function(a) {
  cat("R received: ", a, "\n");

  return(a + 1)
}
