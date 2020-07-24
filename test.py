import beam_pattern_calculator
import numpy as np

import unittest

class TestWrongInput(unittest.TestCase):

    def test_wrong_angle1(self):
        start_azimuth, end_azimuth = -100, 60
        start_elevation, end_elevation = -50, 50
        n_azimuths, n_elevations = 100, 100
        main_lobe, side_lobe = 1, 2
        lobe_width_azimuth, lobe_width_elevation = 3, 4
        self.assertRaises(ValueError, beam_pattern_calculator.BeamPatternCalculator, start_azimuth, end_azimuth,
            start_elevation, end_elevation,
            n_azimuths, n_elevations,
            main_lobe, side_lobe,
            lobe_width_azimuth, lobe_width_elevation)

    def test_wrong_angle2(self):
        start_azimuth, end_azimuth = 100, 60
        start_elevation, end_elevation = -50, 50
        n_azimuths, n_elevations = 100, 100
        main_lobe, side_lobe = 1, 2
        lobe_width_azimuth, lobe_width_elevation = 3, 4
        self.assertRaises(ValueError, beam_pattern_calculator.BeamPatternCalculator, start_azimuth, end_azimuth,
            start_elevation, end_elevation,
            n_azimuths, n_elevations,
            main_lobe, side_lobe,
            lobe_width_azimuth, lobe_width_elevation)

class TestValidResult(unittest.TestCase):

    def test_valid_result(self):
        start_azimuth, end_azimuth = -60, 60
        start_elevation, end_elevation = -50, 50
        n_azimuths, n_elevations = 100, 100
        main_lobe, side_lobe = 1, 2
        lobe_width_azimuth, lobe_width_elevation = 3, 4
        dc = beam_pattern_calculator.BeamPatternCalculator(start_azimuth, end_azimuth,
        start_elevation, end_elevation,
        n_azimuths, n_elevations,
        main_lobe, side_lobe,
        lobe_width_azimuth, lobe_width_elevation)

        installation_angles = np.asarray([[30, 20], [25, 15], [10, 40]], dtype='float64')
        diagram_matrix = dc.calculate(installation_angles)
        self.assertEqual(diagram_matrix.shape, (3, 2))

if __name__ == '__main__':
    unittest.main()
