/*
 * Controlling the FMC ADC data
 */

#include <inttypes.h>
#include <halcs_client.h>

#define DFLT_BIND_FOLDER            "/tmp/halcs"

#define DFLT_HALCS_NUMBER             0
#define MAX_HALCS_NUMBER              1

#define DFLT_BOARD_NUMBER           0

void print_help (char *program_name)
{
    printf( "Usage: %s [options]\n"
            "\t-h This help message\n"
            "\t-v Verbose output\n"
            "\t-b <broker_endpoint> Broker endpoint\n"
            "\t-board <AMC board = [0|1|2|3|4|5]>\n"
            "\t-halcs <HALCS number = [0|1]>\n", program_name);
}

int main (int argc, char *argv [])
{
    int verbose = 0;
    char *broker_endp = NULL;
    char *board_number_str = NULL;
    char *halcs_number_str = NULL;
    char **str_p = NULL;

    if (argc < 2) {
        print_help (argv[0]);
        exit (1);
    }

    /* FIXME: This is rather buggy! */
    /* Simple handling of command-line options. This should be done
     * with getopt, for instance*/
    int i;
    for (i = 1; i < argc; i++)
    {
        if (streq(argv[i], "-v")) {
            verbose = 1;
        }
        else if (streq(argv[i], "-h"))
        {
            print_help (argv [0]);
            exit (1);
        }
        else if (streq (argv[i], "-b")) {
            str_p = &broker_endp;
        }
        /* Fallout for options with parameters */
        else {
            *str_p = strdup (argv[i]);
        }
    }

    /* Set default broker address */
    if (broker_endp == NULL) {
        broker_endp = strdup ("ipc://"DFLT_BIND_FOLDER);
    }

    /* Set default board number */
    uint32_t board_number;
    if (board_number_str == NULL) {
        fprintf (stderr, "[client:acq]: Setting default value to BOARD number: %u\n",
                DFLT_BOARD_NUMBER);
        board_number = DFLT_BOARD_NUMBER;
    }
    else {
        board_number = strtoul (board_number_str, NULL, 10);
    }

    /* Set default halcs number */
    uint32_t halcs_number;
    if (halcs_number_str == NULL) {
        fprintf (stderr, "[client:leds]: Setting default value to HALCS number: %u\n",
                DFLT_HALCS_NUMBER);
        halcs_number = DFLT_HALCS_NUMBER;
    }
    else {
        halcs_number = strtoul (halcs_number_str, NULL, 10);

        if (halcs_number > MAX_HALCS_NUMBER) {
            fprintf (stderr, "[client:leds]: HALCS number too big! Defaulting to: %u\n",
                    MAX_HALCS_NUMBER);
            halcs_number = MAX_HALCS_NUMBER;
        }
    }

    char service [50];
    snprintf (service, sizeof (service), "HALCS%u:DEVIO:FMC130M_4CH%u",
            board_number, halcs_number);

    halcs_client_t *halcs_client = halcs_client_new (broker_endp, verbose, NULL);
    if (halcs_client == NULL) {
        fprintf (stderr, "[client:acq]: halcs_client could be created\n");
        goto err_halcs_client_new;
    }

    uint32_t adc_data;
    halcs_client_err_e err = halcs_get_adc_data0 (halcs_client, service, &adc_data);
    if (err != HALCS_CLIENT_SUCCESS){
        fprintf (stderr, "[client:acq]: halcs_get_adc_data0 failed\n");
        goto err_get_adc_data;
    }

    fprintf (stdout, "[client:adc_data]: data0 = %d\n", (int16_t) adc_data);

    err = halcs_get_adc_data1 (halcs_client, service, &adc_data);
    if (err != HALCS_CLIENT_SUCCESS){
        fprintf (stderr, "[client:acq]: halcs_get_adc_data1 failed\n");
        goto err_get_adc_data;
    }

    fprintf (stdout, "[client:adc_data]: data1 = %d\n", (int16_t) adc_data);

    err = halcs_get_adc_data2 (halcs_client, service, &adc_data);
    if (err != HALCS_CLIENT_SUCCESS){
        fprintf (stderr, "[client:acq]: halcs_get_adc_data2 failed\n");
        goto err_get_adc_data;
    }

    fprintf (stdout, "[client:adc_data]: data2 = %d\n", (int16_t) adc_data);

    err = halcs_get_adc_data3 (halcs_client, service, &adc_data);
    if (err != HALCS_CLIENT_SUCCESS){
        fprintf (stderr, "[client:acq]: halcs_get_adc_data3 failed\n");
        goto err_get_adc_data;
    }

    fprintf (stdout, "[client:adc_data]: data3 = %d\n", (int16_t) adc_data);

err_halcs_client_new:
err_get_adc_data:
    halcs_client_destroy (&halcs_client);
    str_p = &broker_endp;
    free (*str_p);
    broker_endp = NULL;
    str_p = &board_number_str;
    free (*str_p);
    board_number_str = NULL;
    str_p = &halcs_number_str;
    free (*str_p);
    halcs_number_str = NULL;
    return 0;
}
