package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class MaxTrappedWater {
  @EpiTest(testDataFile = "max_trapped_water.tsv")

  public static int getMaxTrappedWater(List<Integer> heights) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxTrappedWater.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
