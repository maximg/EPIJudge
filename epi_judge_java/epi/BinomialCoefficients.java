package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class BinomialCoefficients {
  @EpiTest(testfile = "binomial_coefficients.tsv")

  public static int computeBinomialCoefficient(int n, int k) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
