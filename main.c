#include <stdio.h>
#include <math.h>

/*
             Algoritma Neural Network Manual

 * Input Layer = 3 nodes
 * Hidden Layer = 3 nodes
 * Output Layer = 3 nodes
 */

#define EULER 2.71828

double activation_sigmoid(double x)
{
    return 1 / (1 + pow(EULER, -(x)));
}

int main(void)
{
    // Generate Data from Input layers
    double input_layer[3][1] = {
        {1.0},
        {0.5},
        {-1.5},
    };

    // Generate Data from hidden layer1
    double weight_hidden_input_1[3][3] = {
        {0.28677805, -0.07982693, 0.37394315},
        {0.8793217, -0.13518851, -0.13517904},
        {0.91175894, 0.44307865, -0.27105116},
    };

    // Results from calcuating Matrix Multiplicatication between weight_hiden_input_1 and Input Layers
    double hidden_inputs[3][1];

    // Results of calculating Sigmoid from hidden_inputs
    double hidden_outputs[3][1];

    // Generate Data from hidden layer2
    double weight_hidden_output_2[3][3] = {
        {0.31324719, -0.26755433, -0.2688892},
        {0.13969698, -1.10463286, -0.99588177},
        {-0.32463686, -0.58475832, 0.18143078},
    };

    // Results from calcuating Matrix Multiplicatication between weight_hidden_output_2 and hidden_outputs
    double final_inputs[3][1];

    // Results of calculating Sigmoid from final_inputs
    double final_outputs[3][1];

    int i, j, k;

    // Results from calcuating Matrix Multiplicatication between weight_hiden_input_1 and Input Layers
    for (i = 0; i < sizeof(weight_hidden_input_1) / sizeof(weight_hidden_input_1[0]); i++)
    {
        for (j = 0; j < sizeof(hidden_inputs[0]) / sizeof(hidden_inputs[0][0]); j++)
        {
            hidden_inputs[i][j] = 0;
            for (k = 0; k < sizeof(weight_hidden_input_1[0]) / sizeof(weight_hidden_input_1[0][0]); k++)
            {
                hidden_inputs[i][j] += weight_hidden_input_1[i][k] * input_layer[k][j];
            }
        }
    }

    // Calculating Sigmoid from hidden_inputs
    for (i = 0; i < sizeof(hidden_inputs) / sizeof(hidden_inputs[0]); i++)
    {
        for (j = 0; j < sizeof(hidden_inputs[0]) / sizeof(hidden_inputs[0][0]); j++)
        {
            hidden_outputs[i][j] = activation_sigmoid(hidden_inputs[i][j]);
        }
    }

    // Calcuating Matrix Multiplicatication between weight_hidden_output_2 and hidden_outputs
    for (i = 0; i < sizeof(weight_hidden_output_2) / sizeof(weight_hidden_output_2[0]); i++)
    {
        for (j = 0; j < sizeof(final_inputs[0]) / sizeof(final_inputs[0][0]); j++)
        {
            final_inputs[i][j] = 0;
            for (k = 0; k < sizeof(weight_hidden_output_2[0]) / sizeof(weight_hidden_output_2[0][0]); k++)
            {
                final_inputs[i][j] += weight_hidden_output_2[i][k] * hidden_outputs[k][j];
            }
        }
    }

    // Calculating Sigmoid from final_inputs
    for (i = 0; i < sizeof(final_inputs) / sizeof(final_inputs[0]); i++)
    {
        for (j = 0; j < sizeof(final_inputs[0]) / sizeof(final_inputs[0][0]); j++)
        {
            final_outputs[i][j] = activation_sigmoid(final_inputs[i][j]);
        }
    }

    // Output from final_outputs
    for (i = 0; i < sizeof(final_outputs) / sizeof(final_outputs[0]); i++)
    {
        for (j = 0; j < sizeof(final_outputs[0]) / sizeof(final_outputs[0][0]); j++)
        {
            printf("%f ", final_outputs[i][j]);
        }
        printf("\n");
    }

    return 0;
}
