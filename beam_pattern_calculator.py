import beam_pattern_calculator_bind
import numpy as np

class BeamPatternCalculator(beam_pattern_calculator_bind.BeamPatternCalculator):
    def calculate(self, installation_angles):
        matrix_list = super().calculate(installation_angles)
        return np.asarray(matrix_list)
